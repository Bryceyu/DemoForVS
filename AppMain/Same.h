#pragma once

// ����2��һ�����࣬Ȼ��̳�
class CSame
{
public:
	CSame();
	~CSame();
	void function();
	virtual void vfunction();
	int m_iData = 1;
private:
	int m_Data = 11;
};

class CSameDerived : public CSame
{
public:
	CSameDerived();
	~CSameDerived();
	void function();
	virtual void vfunction();
	int m_iData = 2;
private:
	int m_Data = 22;
};


