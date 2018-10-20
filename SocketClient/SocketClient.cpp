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
	//初始化网络环境
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("WSAStartup failed\n");
		return -1;
	}
	// 初始化完成，创建一个TCP的socket
	SOCKET sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sServer == INVALID_SOCKET)
	{
		printf("socket failed\n");
		return -1;
	}
	//指定连接的服务端信息
	SOCKADDR_IN addrServ;
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons(PORT);
	//客户端只需要连接指定的服务器地址，127.0.0.1是本机的回环地址
	addrServ.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	// 服务器Bind 客户端是进行连接
	int ret = connect(sServer, (SOCKADDR*)&addrServ, sizeof(SOCKADDR));//开始连接
	if (SOCKET_ERROR == ret)
	{
		printf("socket connect failed\n");
		WSACleanup();
		closesocket(sServer);
		return -1;
	}
	//连接成功后，就可以进行通信了
	char szBuf[1024];		
	int i = 0;
	//当服务端是recv的时候，客户端就需要send，若两端同时进行收发则会卡在这里，因为recv和send是阻塞的
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
	//关闭连接
	//closesocket(sServer);
	//WSACleanup();
	return 0;
}
