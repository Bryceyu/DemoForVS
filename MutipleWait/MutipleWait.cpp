// MutipleWait.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>

HANDLE g_hEvent_1 = NULL;
HANDLE g_hEvent_2 = NULL;

DWORD WINAPI Thread_1(LPVOID lpThreadParameter)
{
	Sleep(5 * 1000);
	
	SetEvent(g_hEvent_1);
	ResetEvent(g_hEvent_1);

	Sleep(5 * 1000);

	SetEvent(g_hEvent_2);

	return 0;
}


int main()
{
	g_hEvent_1 = CreateEvent(NULL, TRUE, FALSE, NULL);
	g_hEvent_2 = CreateEvent(NULL, TRUE, FALSE, NULL);


	HANDLE hThread_1 = CreateThread(NULL, 0, Thread_1, NULL, 0, NULL);
	HANDLE hEvents[2] = { g_hEvent_1, g_hEvent_2 };

	DWORD dwRet = WaitForMultipleObjects(2, hEvents, TRUE, INFINITE);


	return 0;
}

