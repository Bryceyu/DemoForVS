#include "stdafx.h"
#include "DefaultDelete.h"


/*
下面的代码会产生编译错误，因为DefaultDelete.h头文件中已经用了c++11的关键词Default，
系统已经生成了默认的对应函数，这里再定义，就会产生这类错误。
already has a body
*/


//CDefaultDelete::CDefaultDelete() /* = default*/
//{
//}
//
//CDefaultDelete::CDefaultDelete(const CDefaultDelete& rhl) /* = default*/
//{
//}
//
//CDefaultDelete& CDefaultDelete::operator=(const CDefaultDelete& rhl) /*= default*/
//{
//}
//
//CDefaultDelete::~CDefaultDelete() /*= default*/
//{
//}
