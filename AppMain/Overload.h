#pragma once
#include <string>
using namespace std;
class COverload
{
public:
	COverload();
	~COverload();
	// 以下三种不能是重载，调用时会编译错误，但是定义时编译不出错误！
	void function(std::string s);
private:
	void function(std::string& s);
	void function(const std::string& s);
};

