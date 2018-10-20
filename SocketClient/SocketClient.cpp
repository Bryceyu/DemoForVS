#include "stdafx.h"
#include <stdio.h>
#include <winsock2.h>
#include <Windows.h>

#pragma comment(lib,"ws2_32.lib")
#define  PORT 6000
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//
//Severity	Code	Description	Project	File	Line	Suppression State
//Error	C4996	'inet_addr': Use inet_pton() or InetPton() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings	SocketClient	c : \users\ripple\desktop\projects\demo4vs2015\socketclient\socketclient.cpp	31

int main(int argc, char * argv[])
{
	//��ʼ�����绷��
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("WSAStartup failed\n");
		return -1;
	}
	// ��ʼ����ɣ�����һ��TCP��socket
	SOCKET sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sServer == INVALID_SOCKET)
	{
		printf("socket failed\n");
		return -1;
	}
	//ָ�����ӵķ������Ϣ
	SOCKADDR_IN addrServ;
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons(PORT);
	//�ͻ���ֻ��Ҫ����ָ���ķ�������ַ��127.0.0.1�Ǳ����Ļػ���ַ
	addrServ.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	// ������Bind �ͻ����ǽ�������
	int ret = connect(sServer, (SOCKADDR*)&addrServ, sizeof(SOCKADDR));//��ʼ����
	if (SOCKET_ERROR == ret)
	{
		printf("socket connect failed\n");
		WSACleanup();
		closesocket(sServer);
		return -1;
	}
	//���ӳɹ��󣬾Ϳ��Խ���ͨ����
	char szBuf[1024];		
	int i = 0;
	//���������recv��ʱ�򣬿ͻ��˾���Ҫsend��������ͬʱ�����շ���Ῠ�������Ϊrecv��send��������
	while (true)
	{
		memset(szBuf, 0, sizeof(szBuf));
		sprintf_s(szBuf, sizeof(szBuf), "Hello server %d", i++);
		ret = send(sServer, szBuf, strlen(szBuf), 0);		
		Sleep(3000);

		if (i == 3)
		{
			Sleep(INFINITE);
		}
	}
	

	//if (SOCKET_ERROR == ret)
	//{
	//	printf("socket send failed\n");
	//	closesocket(sServer);
	//	return -1;
	//}

	//ret = recv(sServer, szBuf, sizeof(szBuf), 0);
	//if (SOCKET_ERROR == ret)
	//{
	//	printf("socket recv failed\n");
	//	closesocket(sServer);
	//	return -1;
	//}
	//printf("%s\n", szBuf);
	//�ر�����
	//closesocket(sServer);
	//WSACleanup();
	return 0;
}
