#include "stdafx.h"
#include "TestMove.h"
#include "iostream"

void process_value(int& i) {
	std::cout << "LValue processed: " << i << std::endl;
}

void process_value(int&& i) {
	std::cout << "RValue processed: " << i << std::endl;
}

void forward_value(int&& i) {
	process_value(i);
}

void TestMove()
{

	//std::string str = "Hello";
	//std::vector<std::string> v;
	////���ó���Ŀ������캯�����½��ַ����飬��������
	//v.push_back(str);
	//std::cout << "After copy, str is \"" << str << "\"\n";
	////�����ƶ����캯�����Ϳ�str���Ϳպ���ò�Ҫʹ��str
	//v.push_back(std::move(str));

	//int i = 0;
	//process_value(i); 
	//std::move(i);
	//std::forward(i);
	//process_value(std::move(i));
	//process_value(1);
	//forward_value(2);

	int&& a = 1;
	//int&& b = i;
	int&& c = a + 2;
	const int & d = 3;
	int & e = c;
}

