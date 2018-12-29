#include<time.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<fstream>
#include<string.h>
//#include"qiujie.h"
using namespace std;

int main(void)
{
	//Éú³ÉÖÕ¾Ö
	ofstream outFile;
	outFile.open("test.txt");
	long n;
	long count_a;
	long count = 0;
	char a[1600];
	char shudu[9][9];
	cin >> n;
	clock_t t = clock();
	int shift[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };
	for (int i = 0; i < 6 && n; i++)
	{
		if (i)
		{
			next_permutation(shift + 3, shift + 6);
			shift[6] = 2, shift[7] = 5, shift[8] = 8;
		}
		for (int j = 0; j < 6 && n; j++)
		{
			if (j) next_permutation(shift + 6, shift + 9);
			char row[10] = "612345789";
			for (int k = 0; k < 40320 && n; k++)
			{
				count++;
				if (k) next_permutation(row + 1, row + 9);
				if (count % 8 == 1)
				{
					count_a = 0;
					memset(a, '\0', sizeof(a));
				}
				for (int r = 0; r < 9; r++)
				{
					for (int c = 0; c < 9; c++)
					{
						shudu[r][c]= row[(c + shift[r]) % 9];
					}
				}
				shudu[1][2] = '0';
				shudu[0][1] = '0';

				shudu[0][4] = '0'; 
				shudu[2][3] = '0';

				shudu[1][7] = '0';
				shudu[2][8] = '0';

				shudu[3][1] = '0';
				shudu[4][2] = '0';

				shudu[3][5] = '0';
				shudu[4][4] = '0';

				shudu[4][6] = '0';
				shudu[5][7] = '0';

				shudu[7][0] = '0';
				shudu[8][2] = '0';

				shudu[6][4] = '0';
				shudu[8][5] = '0';

				shudu[7][8] = '0';
				shudu[6][6] = '0';

				int zero_sum = rand() % 31 + 12;
				for (int k = 0; k < zero_sum; k++)
				{
					int xi = rand() % 9;
					int yi = rand() % 9;
					if (shudu[xi][yi] != '0') shudu[xi][yi] = '0';
					else k--;
				}
				for (int r = 0; r < 9; r++)
				{

					for (int c = 0; c < 9; c++)
					{
						a[count_a++] = shudu[r][c];
						if(c!=8) 
						a[count_a++] = ' ';
					}
					if (count != n || (count == n && r != 8))
						a[count_a++] = '\n';
				}
				
				if(count!=n)
				a[count_a++] = '\n';
				if (count == n ||count % 8 == 0)
				{
					outFile << a;
				}

				if (count == n)
				{
					cout << "The run time is: " << 1000*(double)(clock() - t) / CLOCKS_PER_SEC << "ms" << endl;
					for (i = 0; i < 9; i++)
					{
						for (j = 0; j < 9; j++)
							cout << shudu[i][j];
						cout << endl;
					}
					outFile.close();
					return 0;
				}
			}
		}
	}

	
 }

