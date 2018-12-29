#include"pch.h"
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include<time.h>
#include<algorithm>
#include"sudoku.h"

using namespace std;

void ShuDu::SolveShuDu(char infile[])
{
	clock_t t = clock();
	FILE *fp ;
	
	State_Solve = fopen_s(&fp,infile , "r");
	ofstream Out_SolveShuDu("sudoku.txt");

	char old_data[100];
	int count = 0;//输入的行数
	
	while (fgets(old_data, 20, fp))
	{
		if (strcmp(old_data, "\n") == 0)
			continue;
		InputShuDu(count, old_data);
		count++;
		if (count == 9)
		{
			//输入完毕，解数独
			IsSolve = false;
			Solve(0, 0);

			count = 0;
			char output[165] = { 0 };
			int p = 0;

			//生成数独间空行
			if (!IsFirstShuDu)
				Out_SolveShuDu << endl << endl;
			IsFirstShuDu = false;

			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					output[p++] = map[i][j];
					if (i != 8 && (p + 1) % 18 == 0)
						output[p++] = '\n';
					else if (i == 8 && (p + 1) % 18 == 0)
						continue;
					else
						output[p++] = ' ';
				}
			}
			//输出数独
			Out_SolveShuDu << output;
			memset(set_security, 0, sizeof(set_security));
		}
	}
	printf("程序运行时间为 %f ms\n", 1000 * static_cast<float>(clock() - t) / CLOCKS_PER_SEC);
}
void ShuDu::InputShuDu(int row, char *old_data)
{
	for (int l = 0; l < 17; l++)
	{
		if (l % 2 == 1)
			continue;
		else
		{
			map[row][l / 2] = old_data[l];
			set_security[0][row][old_data[l] - '0'] = 1;
			set_security[1][l / 2][old_data[l] - '0'] = 1;
			set_security[2][row / 3 * 3 + l / 6][old_data[l] - '0'] = 1;
		}
	}
}

void ShuDu::Solve(int row, int col)
{
	while (map[row][col] != '0')
	{
		if (col < 8) col++;
		else
		{
			col = 0;
			row++;
		}
		if (row == 9)
		{
			IsSolve = true;
			return;
		}
	}
	bool IsSearch= false;
	for (int i = 1; i < 10; i++)
	{
		if (set_security[0][row][i] == 0 && set_security[1][col][i] == 0 && set_security[2][row / 3 * 3 + col / 3][i] == 0)
		{
			map[row][col] = i + '0';
			set_security[0][row][i] = 1;
			set_security[1][col][i] = 1;
			set_security[2][row / 3 * 3 + col / 3][i] = 1;
			IsSearch = true;
			Solve(row, col);
		}
		if (IsSearch)
		{
			if (IsSolve)
				return;
			else
			{
				map[row][col] = '0';
				set_security[0][row][i] = 0;
				set_security[1][col][i] = 0;
				set_security[2][row / 3 * 3 + col / 3][i] = 0;
			}
			IsSearch = false;
		}
	}
}

int ShuDu::CreateShuDu(int n)
{
	//生成终局
	clock_t t = clock();
	
	ofstream outFile;
	outFile.open("sudoku.txt");

	if (n <= 0 || n > 1000000)
	{
		State_Create = -1;
		return 0;
	}
	int count_output = 0;
	int count = 0;    //生成数独数目
	char* output = (char*)malloc(200 * n * sizeof(char));
	memset(output, '\0', sizeof(output));
	
	int source[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };
	for (int i = 0; i < 6 && n; i++)
	{
		if (i)
		{
			next_permutation(source + 3, source + 6);
			source[6] = 2, source[7] = 5, source[8] = 8;
		}
		for (int j = 0; j < 6 && n; j++)
		{
			if (j) 
				next_permutation(source + 6, source + 9);
			char row[10] = "612345789";
			for (int k = 0; k < 40320 && n; k++)
			{
				count++;
				if (k)
					next_permutation(row + 1, row + 9);
				for (int r = 0; r < 9; r++)
				{

					for (int c = 0; c < 9; c++)
					{
						output[count_output++] = row[(c + source[r]) % 9];
						if (c != 8)
							output[count_output++] = ' ';
					}
					if (count != n || (count == n && r != 8))
						output[count_output++] = '\n';
				}
				if (count != n)
					output[count_output++] = '\n';
				if (count == n)
				{
					outFile << output;
				}

				if (count == n)
				{
					cout << "The run time is: " << 1000 * (double)(clock() - t) / CLOCKS_PER_SEC << "ms" << endl;
					outFile.close();
					return 0;
				}
			}
		}
	}
}