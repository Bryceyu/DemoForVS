#pragma once


// =default �� =delete ֻ�����Ĭ�ϵ�6�����⺯�������Σ�Ĭ�Ϲ��캯��+Ĭ�Ͽ�������+Ĭ�ϸ��ƹ���+��������+Ĭ����ֵ��2������
class CDefaultDelete
{
public:
	CDefaultDelete() = default; // �������Ϊdefault���Ͳ������Լ����庯�����ˣ�ϵͳ������Ĭ�ϵ�
	//CDefaultDelete(int x) = default; //error
	CDefaultDelete(const CDefaultDelete& rhl) = default; // ͬ�ϣ��������Ϊdefault���Ͳ������Լ����庯�����ˣ�ϵͳ������Ĭ�ϵ�
	CDefaultDelete& operator = (const CDefaultDelete& rhl) = default;// ͬ�ϣ��������Ϊdefault���Ͳ������Լ����庯�����ˣ�ϵͳ������Ĭ�ϵ�
	~CDefaultDelete() = default; // ͬ�ϣ��������Ϊdefault���Ͳ������Լ����庯�����ˣ�ϵͳ������Ĭ�ϵ�
	CDefaultDelete(CDefaultDelete&& rhl) = default;
	CDefaultDelete& operator = (CDefaultDelete&& rhl) = default;
};

