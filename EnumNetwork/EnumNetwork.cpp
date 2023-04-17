#include <stdio.h>
#include <WinSock.h>
#include <stdlib.h>
#pragma comment(lib, "wsock32.lib")
int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	char caHostname[255 + 1];
	PHOSTENT hostData;
	char* pIP;
	int i = 0;
	wVersionRequested = MAKEWORD(1, 1);
	if (WSAStartup(wVersionRequested, &wsaData) != 0)
	{
		printf("Error......code is not compartible with platform\n");
    exit(EXIT_FAILURE);
	}
	if (gethostname(caHostname, sizeof caHostname) != 0)
		printf("Error......Hostname not found\n");
	printf("HOSTNAME : %s\n", caHostname);
	if ((hostData = gethostbyname(caHostname)) == NULL)
	{
		printf("Error......code is not compartible with platform\n");
		exit(EXIT_FAILURE);
	}
	while (hostData->h_addr_list[i])
	{
		pIP = inet_ntoa(*(struct in_addr*)hostData->h_addr_list[i]);
		printf("IP ADDRESS %d: %s\n", ++i, pIP);
	}
	return 0;
}
