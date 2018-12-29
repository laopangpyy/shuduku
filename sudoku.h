#pragma once

class ShuDu
{
public:
	int CreateShuDu(int n);
	void SolveShuDu(char*);
	void Solve(int r, int c);
	void InputShuDu(int row, char *save);
	int State_Create = 0;
	int State_Solve = 1;

//private:
	int set_security[3][10][10] = {0};
	char map[9][9] = {0};
	bool IsSolve = false;
	bool IsFirstShuDu = true;

};

int main(int argc, char**argv);
