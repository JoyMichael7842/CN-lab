#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 10200
#include "socketfun.h"
#define BUF_LEN 20

int main()
{
  int newsockfd = CreateServerSocket("127.0.0.1",10000);
  performServerTask(newsockfd);
}
