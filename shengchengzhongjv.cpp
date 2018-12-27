#include"pch.h"
#include<time.h>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<fstream>
using namespace std;
int main(void)
{
	//生成终局
	ofstream outFile;
	outFile.open("test.txt");
	int n;
	int count_a = 0;
	int count = 0;
	
	cin >> n;
	char* a= (char*)malloc(200*n * sizeof(char));
	memset(a, '\0', sizeof(a));
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
			char row[10] = "512346789";
			for (int k = 0; k < 40320 && n; k++)
			{
				count++;
				if (k) 
					next_permutation(row + 1, row + 9);
				for (int r = 0; r < 9; r++)
				{
				
					for (int c = 0; c < 9; c++)
					{
						a[count_a++] = row[(c + shift[r]) % 9];
						if(c!=8)
						a[count_a++] = ' ';
					}
					if(count!=n||(count==n&&r!=8))
					a[count_a++] = '\n';
				}
				if(count!=n)
				a[count_a++] = '\n';
				if (count == n )
				{
					outFile << a;
				}
				
				if (count == n)
				{
					cout << "The run time is: " << 1000*(double)(clock() - t) / CLOCKS_PER_SEC << "ms" << endl;
					outFile.close();
					return 0;
				}
			}
		}
	}
 }
