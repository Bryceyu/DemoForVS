#include "stdafx.h"
#include <string>
#include <vector>
#include "Header.h"
#include "Header1.h"

void func()
{
	if (true)
	{
		add(1, 2);
		add(1.0f, 2.0f);
		add(1.0, 2.0);
	}

	if (true)
	{
		MyClass cl;
		cl.func1();
	}

	if (false)
	{
		//func1();
	}

	std::string *pstr = new std::string("Hello World!");
	pstr->back();
	std::to_string(10);

	std::vector<int> *pVev = new std::vector<int>();
	pVev->push_back(98);
}