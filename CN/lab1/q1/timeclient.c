#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include "socketfun.h"

int main()
{
  int sockfd = CreateClientSocket("127.0.0.1",10000);
  PerformClientTask(sockfd);
}
