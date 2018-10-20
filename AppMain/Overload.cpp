#include "stdafx.h"
#include "Overload.h"
#include <iostream>

COverload::COverload()
{
}


COverload::~COverload()
{
}

void COverload::function(std::string s)
{
	cout << "COverload::function(std::string s)" << endl;
}

void COverload::function(std::string & s)
{
	cout << "COverload::function(std::string & s)" << endl;
}

void COverload::function(const std::string& s)
{
	cout << "COverload::function(const std::string& s)" << endl;
}