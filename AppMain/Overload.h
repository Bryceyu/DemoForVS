#pragma once
#include <string>
using namespace std;
class COverload
{
public:
	COverload();
	~COverload();
	// �������ֲ��������أ�����ʱ�������󣬵��Ƕ���ʱ���벻������
	void function(std::string s);
private:
	void function(std::string& s);
	void function(const std::string& s);
};

