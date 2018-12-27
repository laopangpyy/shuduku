#include"pch.h"
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include<time.h>
using namespace std;
ofstream OutputFileSolveSudoku("sudoku.txt");
char vis[3][10][10];
char map[9][9];
bool IsFindAns = false, IsFirstQuestion = true;

void InputSudokuQuestion(int row, char* save);

void SolveSudoku(int r, int c);

void OutputSolveSudoku()

{

	char outputsave[165] = {0};

	int p = 0;
	
	if (!IsFirstQuestion)
		OutputFileSolveSudoku << endl<<endl;
	IsFirstQuestion = false;
	for (int i = 0; i < 9; i++)

	{

		for (int j = 0; j < 9; j++)

		{

			outputsave[p++] = map[i][j];

			if (i != 8 && (p + 1) % 18 == 0)
				outputsave[p++] = '\n';
			else if (i == 8 && (p + 1) % 18 == 0)
				continue;
			else
				outputsave[p++] = ' ';

		}

	}
	
	OutputFileSolveSudoku << outputsave;

}

void InputSudokuQuestion(int row, char *save)

{
	for (int j = 0; j < 17; j++)

	{
		if (j % 2 == 0)
		{
			map[row][j / 2] = save[j];
			vis[0][row][save[j] - '0'] = 1;
			vis[1][j/2][save[j] - '0'] = 1;
			vis[2][row / 3 * 3 + j / 6][save[j] - '0'] = 1;
		}
	}
}

void SolveSudoku(int r, int c)

{

	while (map[r][c] != '0')

	{

		if (c < 8) c++;

		else c = 0, r++;

		if (r == 9)

		{

			IsFindAns = true;

			return;

		}

	}

	bool isSearch = false;

	for (int i = 1; i < 10; i++)

	{

		if (vis[0][r][i] == 0 && vis[1][c][i] == 0 && vis[2][r / 3 * 3 + c / 3][i] == 0)

		{

			vis[0][r][i] = 1;

			vis[1][c][i] = 1;

			vis[2][r / 3 * 3 + c / 3][i] = 1;

			map[r][c] = i + '0';

			isSearch = true;

			SolveSudoku(r, c);

		}

		if (isSearch)

		{

			isSearch = false;

			if (IsFindAns)

				return;

			else

			{
				map[r][c] = '0';
				vis[0][r][i] = 0;
				vis[1][c][i] = 0;
				vis[2][r / 3 * 3 + c / 3][i] = 0;
			}

		}

	}

}
int main(void)
{
	clock_t t = clock();
	FILE *fp1;
	fopen_s(&fp1,"C:\\Users\\aoaoao\\source\\repos\\ConsoleApplication1\\ConsoleApplication1\\test.txt", "r");
	char save[100];
	int cnt = 0;

	while (fgets(save, 20, fp1))
	{
		if (strcmp(save, "\n") == 0)

			continue;

		InputSudokuQuestion(cnt, save);

		cnt++;

		if (cnt == 9)

		{

			IsFindAns = false;

			SolveSudoku(0, 0);

			cnt = 0;

			OutputSolveSudoku();

			memset(vis, 0, sizeof(vis));

		}

	}
	printf("程序运行时间为 %f ms\n", 1000 * static_cast<float>(clock() - t) / CLOCKS_PER_SEC);
}
