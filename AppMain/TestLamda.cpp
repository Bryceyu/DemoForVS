#include "stdafx.h"
#include "TestLamda.h"
#include <iostream>
using namespace std;


void TestLamda()
{
	// 测试lambda表达式的用法，其类似于一个仿函数（函数对象）
	int id1 = 1;
	int id2 = 10;
	auto lambdas1 = [id1, &id2](int param)mutable->void {
		cout << id1 << endl << id2 << endl << param << endl;
		cout << "---------------------------------" << endl;
		++id1;
		++id2;
		++param;
	};

	lambdas1(7);
	lambdas1(8);
	lambdas1(9);
	cout << id1 << endl << id2 << endl;
}

