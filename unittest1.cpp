#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/sudoku.h"
#include <assert.h>
#include<cstdio>
#include<iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)//ʹ����ȷ�𰸲���InputShuDu�����Ƿ���ȷת������
		{
			// TODO: �ڴ�������Դ���
			ShuDu test;
			int row = 4;
			char *old_data = "1 0 0 3 6 0 2 0 8";
			//char answer[0]=
			//excepted[0][]=""
			test.InputShuDu(row, old_data);
			Assert::AreEqual(test.map[row][0], '1');
			Assert::AreEqual(test.map[row][1], '0');
			Assert::AreEqual(test.map[row][2], '0');
			Assert::AreEqual(test.map[row][3], '3');
			Assert::AreEqual(test.map[row][4], '6');
			Assert::AreEqual(test.map[row][5], '0');
			Assert::AreEqual(test.map[row][6], '2');
			Assert::AreEqual(test.map[row][7], '0');
			Assert::AreEqual(test.map[row][8], '8');
			Assert::AreEqual(test.set_security[0][row][0], 1);
			Assert::AreEqual(test.set_security[0][row][1], 1);
			Assert::AreEqual(test.set_security[0][row][2], 1);
			Assert::AreEqual(test.set_security[0][row][3], 1);
			Assert::AreEqual(test.set_security[0][row][4], 0);
			Assert::AreEqual(test.set_security[0][row][5], 0);
			Assert::AreEqual(test.set_security[0][row][6], 1);
			Assert::AreEqual(test.set_security[0][row][7], 0);
			Assert::AreEqual(test.set_security[0][row][8], 1);
			Assert::AreEqual(test.set_security[0][row][9], 0);
		}
		TEST_METHOD(TestMethod2)//ʹ�ô���𰸲���InputShuDu�����Ƿ���ȷת������
		{
			// TODO: �ڴ�������Դ���
			ShuDu test;
			int row = 2;
			char *old_data = "5 0 0 2 0 0 4 5 8";
			test.InputShuDu(row, old_data);
			Assert::AreNotEqual(test.map[row][0], '1');//��Ϊ����
			Assert::AreEqual(test.map[row][1], '0');
			Assert::AreEqual(test.map[row][2], '0');
			Assert::AreEqual(test.map[row][3], '2');
			Assert::AreEqual(test.map[row][4], '0');
			Assert::AreEqual(test.map[row][5], '0');
			Assert::AreEqual(test.map[row][6], '4');
			Assert::AreEqual(test.map[row][7], '5');
			Assert::AreEqual(test.map[row][8], '8');
			Assert::AreEqual(test.set_security[0][row][0], 1);
			Assert::AreEqual(test.set_security[0][row][1], 0);
			Assert::AreEqual(test.set_security[0][row][2], 1);
			Assert::AreEqual(test.set_security[0][row][3], 0);
			Assert::AreEqual(test.set_security[0][row][4], 1);
			Assert::AreEqual(test.set_security[0][row][5], 1);
			Assert::AreEqual(test.set_security[0][row][6], 0);
			Assert::AreEqual(test.set_security[0][row][7], 0);
			Assert::AreEqual(test.set_security[0][row][8], 1);
			Assert::AreEqual(test.set_security[0][row][9], 0);
		}
		TEST_METHOD(TestMethod3)//����CreateShuDu������������Ŀ�Ϸ��Ե��ж�
		{
			// TODO: �ڴ�������Դ���
			ShuDu test;
			test.CreateShuDu(30);//������Ŀ�Ϸ�
			Assert::AreEqual(test.State_Create, 0);
		}
		TEST_METHOD(TestMethod4)//����CreateShuDu������������Ŀ�Ϸ��Ե��жϣ�ͬʱ�ֶ��������ļ�����ȷ��
		{
			// TODO: �ڴ�������Դ���
			ShuDu test;
			test.CreateShuDu(-1);//������Ŀ-1���Ϸ�
			Assert::AreEqual(test.State_Create, -1);
		}
		TEST_METHOD(TestMethod5)//����CreateShuDu������������Ŀ�Ϸ��Ե��жϣ�ͬʱ�ֶ��������ļ�����ȷ��
		{
			// TODO: �ڴ�������Դ���
			ShuDu test;
			test.CreateShuDu(1000004);//������Ŀ1000004���Ϸ�
			Assert::AreEqual(test.State_Create, -1);
		}
		TEST_METHOD(TestMethod6)//����SolveShuDu�����Դ��ļ�״̬���жϣ�ͬʱ�ֶ��������ļ�����ȷ��
		{
			// TODO: �ڴ�������Դ���
			ShuDu test;
			test.SolveShuDu("test.txt");//�������ڵ��ļ�����ȷ��
			Assert::AreEqual(test.State_Solve, 0);
		}
		TEST_METHOD(TestMethod7)//����SolveShuDu�����Դ��ļ�״̬���жϣ�ͬʱ�ֶ��������ļ�����ȷ��
		{
			// TODO: �ڴ�������Դ���
			ShuDu test;
			test.SolveShuDu("omg.txt");//���������ڵ��ļ������ܴ�
			Assert::AreNotEqual(test.State_Solve, 0);
		}
		TEST_METHOD(TestMethod8)//���Ի������������Solve��������ȷ�ԣ���������һ�е���ȷ����Ϊ�Ա�
		{
			// TODO: �ڴ�������Դ���
			ShuDu test;
			test.InputShuDu(0, "0 0 0 3 0 6 0 0 9");
			test.InputShuDu(1, "3 4 0 0 8 0 5 0 2");
			test.InputShuDu(2, "7 8 9 0 1 2 3 0 0");
			test.InputShuDu(3, "1 0 0 4 6 0 0 0 5");
			test.InputShuDu(4, "4 6 0 8 0 5 0 2 0");
			test.InputShuDu(5, "8 0 0 1 2 3 4 0 0");
			test.InputShuDu(6, "2 3 0 0 0 0 0 0 1");
			test.InputShuDu(7, "0 7 0 9 5 1 0 3 0");
			test.InputShuDu(8, "9 5 0 0 3 0 6 0 8");
			test.Solve(0, 0);
			Assert::AreEqual(test.map[0][0], '5');
			Assert::AreEqual(test.map[0][1], '1');
			Assert::AreEqual(test.map[0][2], '2');
			Assert::AreEqual(test.map[0][3], '3');
			Assert::AreEqual(test.map[0][4], '4');
			Assert::AreEqual(test.map[0][5], '6');
			Assert::AreEqual(test.map[0][6], '7');
			Assert::AreEqual(test.map[0][7], '8');
			Assert::AreEqual(test.map[0][8], '9');
		}
		TEST_METHOD(TestMethod9)//���Ի������������Solve��������ȷ�ԣ���������һ�е���ȷ����Ϊ�Ա�
		{
			// TODO: �ڴ�������Դ���
			ShuDu test;
			test.InputShuDu(0, "0 0 0 3 0 6 0 0 9");
			test.InputShuDu(1, "3 4 0 0 8 0 5 0 2");
			test.InputShuDu(2, "7 8 9 0 1 2 3 0 0");
			test.InputShuDu(3, "1 0 0 4 6 0 0 0 5");
			test.InputShuDu(4, "4 6 0 8 0 5 0 2 0");
			test.InputShuDu(5, "8 0 0 1 2 3 4 0 0");
			test.InputShuDu(6, "2 3 0 0 0 0 0 0 1");
			test.InputShuDu(7, "0 7 0 9 5 1 0 3 0");
			test.InputShuDu(8, "9 5 0 0 3 0 6 0 8");
			test.Solve(1, 0);//����ȷ��ڲ�����0��0����Ϊ����ģ�1��0��
			Assert::AreNotEqual(test.map[0][0], '5');
			Assert::AreNotEqual(test.map[0][1], '1');
			Assert::AreNotEqual(test.map[0][2], '2');
			Assert::AreEqual(test.map[0][3], '3');
			Assert::AreNotEqual(test.map[0][4], '4');
			Assert::AreEqual(test.map[0][5], '6');
			Assert::AreNotEqual(test.map[0][6], '7');
			Assert::AreNotEqual(test.map[0][7], '8');
			Assert::AreEqual(test.map[0][8], '9');
		}
		TEST_METHOD(TestMethod10)//���Ի������������Solve��������ȷ�ԣ���������һ�е���ȷ����Ϊ�Ա�
		{
			// TODO: �ڴ�������Դ���
			ShuDu test;
			test.InputShuDu(0, "0 0 0 3 0 6 0 0 9");
			test.InputShuDu(1, "3 4 0 0 8 0 5 0 2");
			test.InputShuDu(2, "7 8 9 0 1 2 3 0 0");
			test.InputShuDu(3, "1 0 0 4 6 0 0 0 5");
			test.InputShuDu(4, "4 6 0 8 0 5 0 2 0");
			test.InputShuDu(5, "8 0 0 1 2 3 4 0 0");
			test.InputShuDu(6, "2 3 0 0 0 0 0 0 1");
			test.InputShuDu(7, "0 7 0 9 5 1 0 3 0");
			test.InputShuDu(8, "9 5 0 0 3 0 6 0 8");
			test.Solve(0, 0);
			Assert::AreNotEqual(test.map[1][0], '2');//��Ϊ����
			Assert::AreEqual(test.map[1][1], '4');
			Assert::AreEqual(test.map[1][2], '6');
			Assert::AreEqual(test.map[1][3], '7');
			Assert::AreEqual(test.map[1][4], '8');
			Assert::AreEqual(test.map[1][5], '9');
			Assert::AreEqual(test.map[1][6], '5');
			Assert::AreEqual(test.map[1][7], '1');
			Assert::AreEqual(test.map[1][8], '2');
		}
		
	};
	
}