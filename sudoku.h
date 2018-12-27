#pragma once

class ShuDu
{
public:
	int CreateShuDu(int n);
	void SolveShuDu(char*);
private:
	char set_security[3][10][10] = {0};
	char map[9][9] = {0};
	bool IsSolve = false;
	bool IsFirstShuDu = true;
	void Solve(int r,int c);
	void InputShuDu(int row, char *save);
};
