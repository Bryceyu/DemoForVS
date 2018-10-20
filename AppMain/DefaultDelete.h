#pragma once


// =default 和 =delete 只能针对默认的6个特殊函数来修饰：默认构造函数+默认拷贝构造+默认复制构造+析构函数+默认右值的2个函数
class CDefaultDelete
{
public:
	CDefaultDelete() = default; // 如果声明为default，就不能再自己定义函数体了，系统会生成默认的
	//CDefaultDelete(int x) = default; //error
	CDefaultDelete(const CDefaultDelete& rhl) = default; // 同上，如果声明为default，就不能再自己定义函数体了，系统会生成默认的
	CDefaultDelete& operator = (const CDefaultDelete& rhl) = default;// 同上，如果声明为default，就不能再自己定义函数体了，系统会生成默认的
	~CDefaultDelete() = default; // 同上，如果声明为default，就不能再自己定义函数体了，系统会生成默认的
	CDefaultDelete(CDefaultDelete&& rhl) = default;
	CDefaultDelete& operator = (CDefaultDelete&& rhl) = default;
};

