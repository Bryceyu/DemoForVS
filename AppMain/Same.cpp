#include "stdafx.h"
#include "Same.h"
#include <iostream>
using namespace std;

CSame::CSame()
{
	cout << "CSame::CSame()" << endl;
}


CSame::~CSame()
{
	cout << "CSame::~CSame()" << endl;
}

void CSame::function()
{
	cout << "CSame::function()" << endl;
}

void CSame::vfunction()
{
	cout << "CSame::vfunction()" << endl;
}

CSameDerived::CSameDerived()
{
	cout << "CSameDerived::CSameDerived()" << endl;
}

CSameDerived::~CSameDerived()
{
	cout << "CSameDerived::~CSameDerived()" << endl;
}

void CSameDerived::function()
{
	cout << "CSameDerived::function()" << endl;
}

void CSameDerived::vfunction()
{
	cout << "CSameDerived::vfunction()" << endl;
}
