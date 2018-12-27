#include"pch.h"
#include<time.h>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<fstream>
#include"sudoku.h"
using namespace std;

int main(int argc, char**argv)
{
	ShuDu test;
	int num=0;
	int length = strlen(argv[2]);
	if (argc == 3 && strcmp(argv[1], "-c") == 0)
	{
		for (int i = 0; i < length; i++)
		{
			if (argv[2][i] >= '0'&&argv[2][i] <= '9')
			{
				num += ((argv[2][i] - '0')*pow(10, length - i - 1));
			}
			else
			{
				cout << "生成终局数量需为数字！" << endl;
				return 0;
			}

		}
		if (num > 1000000 || num <= 0)
		{
			cout << "生成终局数量应在0到1000000之间！" << endl;
			return 0;
		}
		test.CreateShuDu(num);
	}
	else if (argc == 3 && strcmp(argv[1], "-s") == 0)
	{
		test.SolveShuDu(argv[2]);
	}
	else if (argc == 2 || argc == 1)
	{
		cout << "输入参数数目不正确！" << endl;
		return 0;
	}
	else
	{
		cout << "输入错误！" << endl;
		return 0;
	}
	
}


