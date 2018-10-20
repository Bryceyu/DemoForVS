#include "stdafx.h"
#include <windows.h>
#include "TestBugReport.h"
#include <excpt.h>

LONG CALLBACK FirstVectExcepHandler(PEXCEPTION_POINTERS pExcepInfo)
{
	printf("FirstVectExcepHandler\r\n");
	return EXCEPTION_CONTINUE_SEARCH;
}


void InitVEH()
{
	//����1=1��ʾ����Veh����ͷ����=0��ʾ���뵽VEH����β��
	::AddVectoredExceptionHandler(0, &FirstVectExcepHandler);
}

LONG WINAPI TopLevelExcepFilter(PEXCEPTION_POINTERS pExcepInfo)
{
	printf("TopLevelExcepFilter\r\n");
	return EXCEPTION_CONTINUE_SEARCH;
}
void InitTopLevelEH()
{
	::SetUnhandledExceptionFilter(&TopLevelExcepFilter);
}

LONG FirstSEHer()
{
	printf("FirstSEHer\r\n");
	return EXCEPTION_CONTINUE_SEARCH;
}

LONG SecondSEHer()
{
	printf("SecondSEHer\r\n");
	return EXCEPTION_CONTINUE_SEARCH;
}

void TestBugReport()
{
	InitVEH();
	InitTopLevelEH();
	__try
	{
		__try
		{
			int i = 0;
			int j = 9 / i;
		}
		__except (FirstSEHer())
		{
			printf("TestBugReport1\r\n");
		}
	}
	__except (SecondSEHer())
	{
		printf("TestBugReport2\r\n");
	}

}