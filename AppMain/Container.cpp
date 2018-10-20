#include "stdafx.h"
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <unordered_map>
#include <iostream>
#include <assert.h>
using namespace std;

void TestSTLContainer()
{
	// string
	{
		std::string *pstr = new std::string("Hello World!");
		char c = pstr->back();
		int size = sizeof(std::string);
	}


	// vector
	{
		int size = 0;

		std::vector<int> vec_int;
		vec_int.push_back(98);
		size = sizeof(std::vector<int>);
		size = sizeof(vec_int);

		std::vector<std::string> vec_str;
		vec_str.push_back("hello");
		size = sizeof(std::vector<std::string>);
		size = sizeof(vec_str);
	}

	// list
	{
		list<int> mList;
		auto iter = mList.end();
		mList.push_back(1);
		iter = mList.end();
	}

	// hash map
	{
		std::unordered_map<int, std::string>  omap;
		omap[45] = "hello";
		int size = sizeof(omap);
	}

	// map
	{
		std::map<int, std::string> tmap;
		tmap[12] = "hello";
		int size = sizeof(tmap);
	}


	// 测试 map 的查找
	{
		std::map<char*, char*> containerT{
			{ "nihao", "" },{ "hello", "" },{ "chuntan", "" },{ "dongtian", "" },{ "xiatian", "" }
		};

		//
		auto iter1 = containerT.find("hello");
		assert(iter1 != containerT.end());

		// 下面这种方式编译错误，什么原因？
		//auto iter3 = std::find(containerT.begin(), containerT.end(), /*{ "hello", "" }*//*pair<char*, char*>{"hello", ""}*/"hello");
		//if (iter3 == containerT.end())
		//{
		//	return 1;
		//}
	}

}

