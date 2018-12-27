#include"pch.h"
/*#include<stdlib.h>
#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include<time.h>
using namespace std;

#define N 9
int m_searchLength = 0;
int m_shudu[N + 2][N + 1];
int m_solutionID = 0;
int flag = 0;
//第一维0行，1列，2块
int set[3][10][10];
int kuai[11][11];
ifstream infile;
ofstream outfile;

void solve(int searchNodeID, int count);
int isOK(int row, int col, int num);
void display(int id);
void writeFile(int id);

typedef struct _SearchNode
{
	int row;
	int col;
	int data;
}SearchNode;
SearchNode m_searchNode[N * N];

int main(void)
{
	clock_t t = clock();
	infile.open("C:\\Users\\aoaoao\\source\\repos\\ConsoleApplication1\\ConsoleApplication1\\test.txt");
	outfile.open("C:\\Users\\aoaoao\\source\\repos\\ConsoleApplication1\\ConsoleApplication1\\out.txt");
	int count = 0;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			kuai[i][j] = 1;
	for (int i = 1; i <= 3; i++)
		for (int j = 4; j <= 6; j++)
			kuai[i][j] = 2;
	for (int i = 1; i <= 3; i++)
		for (int j = 7; j <= 9; j++)
			kuai[i][j] = 3;
	for (int i = 4; i <= 6; i++)
		for (int j = 1; j <= 3; j++)
			kuai[i][j] = 4;
	for (int i = 4; i <= 6; i++)
		for (int j = 4; j <= 6; j++)
			kuai[i][j] = 5;
	for (int i = 4; i <= 6; i++)
		for (int j = 7; j <= 9; j++)
			kuai[i][j] = 6;
	for (int i = 7; i <= 9; i++)
		for (int j = 1; j <= 3; j++)
			kuai[i][j] = 7;
	for (int i = 7; i <= 9; i++)
		for (int j = 4; j <= 6; j++)
			kuai[i][j] = 8;
	for (int i = 7; i <= 9; i++)
		for (int j = 7; j <= 9; j++)
			kuai[i][j] = 9;
	while (!infile.eof())
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 10; k++)
					set[i][j][k] = 1;
		memset(m_shudu, 0, sizeof(m_shudu));
		memset(m_searchNode, 0, sizeof(m_searchNode));
		m_searchLength = 0;
		count++;
		for (int i = 1; i != 10; i++)
		{
			for (int j = 1; j != 10; j++)
			{
				//if(i%10!=0)
				infile >> m_shudu[i][j];
				if (infile.eof()) break;
				//if (m_shudu[i][j] == '\n')
					//infile >> m_shudu[i][j];
				if (m_shudu[i][j] == 0)
				{
					m_searchLength++;
					m_searchNode[m_searchLength].row = i;
					m_searchNode[m_searchLength].col = j;
				}
			}
			if (infile.eof()) break;
		}
		flag = 0;
		solve(1, count);
		if (infile.eof()) break;
	}
	printf("程序运行时间为 %f ms\n", 1000 * static_cast<float>(clock() - t) / CLOCKS_PER_SEC);
}

void solve(int searchNodeID, int count)
{

	if (m_searchLength + 1 == searchNodeID && flag == 0)
	{
		m_solutionID++;
		writeFile(count);
		flag = 1;
		return;
	}
	int row = m_searchNode[searchNodeID].row;
	int col = m_searchNode[searchNodeID].col;

	for (int i = 1; i != 10; i++)
	{
		m_shudu[row][col] = i;
		if (isOK(row, col, i))
		{

			for (int j = 1; j < 10; j++)
			{
				if (j == row) continue;
				set[0][j][i] = 0;
			}
			for (int j = 1; j < 10; j++)
			{
				if (j == col) continue;
				set[1][j][i] = 0;
			}
			for (int j = 1; j < 10; j++)
			{
				if (j == kuai[row][col]) continue;
				set[2][j][i] = 0;
			}
			solve(searchNodeID + 1, count);

			//row = m_searchNode[searchNodeID + 1].row;
			//col = m_searchNode[searchNodeID + 1].col;
			//m_shudu[row][col] = 0;
			for (int j = 1; j < 10; j++)
			{
				if (j == row) continue;
				set[0][j][i] = 1;
			}
			for (int j = 1; j < 10; j++)
			{
				if (j == col) continue;
				set[1][j][i] = 1;
			}
			for (int j = 1; j < 10; j++)
			{
				if (j == kuai[row][col]) continue;
				set[2][j][i] = 1;
			}
		}
	}
}

int isOK(int row, int col, int num)
{
	if (set[0][row][num] == 1 && set[1][col][num] == 1 && set[2][kuai[row][col]][num] == 1) return 1;
	else return 0;
}

void writeFile(int id)
{
	outfile << "===========================第" << id << "组数独数据=============================" << std::endl;
	char a[200];
	memset(a, '\0', sizeof(char));
	int count_a = 0;
	for (int i = 1; i != 10; i++)
	{
		for (int j = 1; j != 10; j++)
		{
			a[count_a++] = m_shudu[i][j] + '0';
			if (j != 9)
				a[count_a++] = ' ';
		}
		a[count_a++] = '\n';
	}
	outfile << a;
}*/