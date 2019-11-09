// AppMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include "Header.h"
#include "Header1.h"
#include <string.h>
#include <iostream>
#include <unordered_map>
#include "Same.h"
#include "Overload.h"
#include <memory>
#include "TestBugReport.h"
#include "TestMove.h"

using namespace std;

extern void getStr();
//extern void funNotexsit();
//#pragma comment (lib, "..\\Projects\\Demo4VS2005\\debug\\LibTest.lib")

//void func()
//{
//
//}

class MyClass2
{
public:
	MyClass2();
	~MyClass2();
//private:
	MyClass2(const MyClass2&);
	MyClass2 operator = (MyClass2& rhs);
private:
	int a;
	short b;
	char c;
};

MyClass2::MyClass2()
{
	printf("MyClass2::MyClass2()\r\n");
}

MyClass2::MyClass2(const MyClass2&)
{
	printf("MyClass2::MyClass2(const MyClass2&)\r\n");
}

MyClass2::~MyClass2()
{
	printf("MyClass2::~MyClass2()\r\n");
}

MyClass2 MyClass2::operator=(MyClass2& rhs)
{
	printf("MyClass2 MyClass2::operator=(MyClass2 that)\r\n");
	return *this;
}

typedef struct 
{
	int a;
	short b;
	char c;
	int d;
} MyStruct;

class SmallInt
{
public:
	SmallInt(int x);
	explicit SmallInt(int x, int y);
	operator int() const;
	operator float() const;
	int* operator & ();
	//SmallInt operator += (int x);
	int operator += (int x);
private:
	int m_x;
	int m_y;
};

SmallInt::SmallInt(int x)
{
	m_x = x;
	std::cout << x;
	std::cin >> x;
}

SmallInt::SmallInt(int x, int y)
{
	m_x = x;
	m_y = y;
}

SmallInt::operator int() const
{
	return m_x;
}

int* SmallInt::operator&()
{
	return &m_x;
}

// 下面4中操作符必须要是成员函数
//SmallInt operator = (SmallInt x, SmallInt y)
//SmallInt operator [] (SmallInt x, SmallInt y)
//SmallInt operator () (SmallInt x, SmallInt y)
//SmallInt operator -> (SmallInt x, SmallInt y)

SmallInt operator += (SmallInt x, SmallInt y)
{
	return NULL;
}

void function1(SmallInt smallint)
{
	return;
}

MyClass2 function2()
{
	MyClass2 m2 = MyClass2();
	
	return m2;
}

MyStruct function3(int a, int b)
{
	MyStruct m;
	m.a = 0xA;
	m.b = 0xB;
	m.c = 0xC;
	m.d = 0xd;
	return m;
}
struct AStruct;
struct BStruct;

struct AStruct {
	std::shared_ptr<BStruct> bPtr;
	~AStruct() { cout << "AStruct is deleted!" << endl; }
};

struct BStruct {
	std::shared_ptr<AStruct> APtr;
	~BStruct() { cout << "BStruct is deleted!" << endl; }
};

void TestLoopReference()
{
	std::shared_ptr<AStruct> ap(new AStruct);
	std::shared_ptr<BStruct> bp(new BStruct);
	ap->bPtr = bp;
	bp->APtr = ap;
}

class CTestRVO
{
public:
	CTestRVO();
	~CTestRVO();
	CTestRVO(const CTestRVO& rhs);
	static CTestRVO function1()
	{
		CTestRVO c;
		c.m_a = 1;
		c.m_b = 2;
		c.m_c = 3;
		return c;
	}

private:
	int m_a;
	int m_b;
	int m_c;

};

CTestRVO::CTestRVO()
{
	printf("CTestRVO()\r\n");
}

CTestRVO::~CTestRVO()
{
	printf("~CTestRVO()\r\n");
}
CTestRVO::CTestRVO(const CTestRVO& rhs)
{
	printf("CTestRVO(const CTestRVO& rhs)\r\n");
}

//extern void funcB(); // in LibB.lib
//extern void funcA(); // in LibA.lib
int main()
{

	if (true)
	{
		TestMove();
	}

	//if (false)
	//{
	//	// 测试hashfunction
	//	std::hash<int>()(100);
	//	std::shared_ptr<int> p1(new int);
	//	std::shared_ptr<int> p2 = p1;

	//	std::make_shared<int>(2);
	//}

	//if (false)
	//{
	//	// 右值测试
	//	vector<char*> vec;
	//	char* p = reinterpret_cast<char*>(0x1234);
	//	vec.push_back(std::move(p));
	//	printf("p=%p", p);
	//	return 0;
	//}

	if (true)
	{
		int i = 0x1234;
		return 0;
	}

	if (true)
	{
		// 返回值优化测试4
		CTestRVO c = CTestRVO::function1();
	}

	if (true)
	{
		
		// 返回值优化测试3
		MyStruct m3 = function3(0xAA, 0xBB);
		m3.a = 0x1000;
		return 0;
	}

	if (false)
	{
		// 返回值优化测试2
		MyClass2 m2 = function2();
		return 0;
	}

	if (false)
	{
		// 返回值优化测试1
		function2();
		return 0;
	}


	//if (false)
	//{
	//	funcA();
	//	funcB();
	//	return 0;

	//}
	if (false)
	{
		TestBugReport();
		return 0;

	}
	if (false)
	{	
		TestLoopReference();
		return 0;
	}

	if (false)
	{
		MyClass2 my2;
		vector<MyClass2> vec;
		vec.push_back(my2);
		vec.push_back(std::move(my2));
		return 0;
	}

	if (false)
	{
		int sizeOfEmptyClass = sizeof(MyClass2); // ==1
		return 0;
	}

	if (false)
	{
		void* p = operator new(sizeof(std::string));
		new(p)std::string("hello");

		std::string* p2 = new std::string("Hello");
		delete p2;
		return true;
	}

	if (false)
	{
		string str("Hello");
		const string str2 = str;
		const string& str3 = str;
		COverload* p = new COverload;
		//p->function(str3);	//  ambiguous call to overloaded function
	}
	if (false)
	{
		CSame* p = new CSameDerived();
		p->function();
		p->vfunction();
		cout << p->m_iData << endl;
		return 0;
	}

	if (false)
	{
		//sizeof...(int);
		//nullptr
		std::vector<int> x{ 1, 2 };
		for (auto elem : x)
		{
			std::cout << elem << std::endl;
		}
	}

	if (false)
	{
		SmallInt si(2);
		SmallInt sj(3);
		si += sj;
		si = 4;
		//si + 3;
		int i = si.operator int();
		function1(1);

	}

	if (false)
	{
		add(1, 2);
		add(1.0f, 2.0f);
		add(1.0, 2.0);
	}

	if (false)
	{
		//std::map<int, int> m;
		//std::set<int, int> s;
		std::vector<MyClass2> vec;

		MyClass2 obj1;
		vec.push_back(obj1);

		std::vector<MyClass2> vec2(vec);
		less<int>;
	}

	if (false)
	{
		MyClass cl;
		cl.func1();
	}

	if (false)
	{
		//func1();
	}	

	if (true)
	{
		//getStr();
		//funNotexsit();

	}

	return 0;
}

