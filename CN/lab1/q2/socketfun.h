#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORTNO 10200
#define BUF_LEN 20

int CreateClientSocket(char IP[20],int portno)
{
  struct sockaddr_in address;
  int sockfd;
  socklen_t slen= sizeof(address);
  sockfd = socket(AF_INET, SOCK_STREAM,0);


  address.sin_family=AF_INET;
  address.sin_addr.s_addr=inet_addr(IP);
  address.sin_port=htons(portno);
  connect(sockfd, (struct sockaddr *) &address, slen);
  return sockfd;
}

int CreateServerSocket(char IP[20],int portno)
{
  struct sockaddr_in server_addr, client_addr;
  socklen_t slen = sizeof(server_addr);
  int sockfd, newsockfd=-1;


  sockfd = socket(AF_INET, SOCK_STREAM,0);
  server_addr.sin_family=AF_INET;
  server_addr.sin_port=htons(portno);
  server_addr.sin_addr.s_addr= inet_addr(IP);

  bind(sockfd, (struct sockaddr *)&server_addr, slen);
  listen(sockfd, 6);
  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &slen);
  return newsockfd;
}
void PerformClientTask(int sockfd)
{
  char buffer[BUF_LEN];

  while(1)
  {
    printf("Enter a message (or \"QUIT\" to exit):");
    fgets(buffer, BUF_LEN, stdin);

    write(sockfd, buffer, BUF_LEN);

    read(sockfd, buffer, BUF_LEN);

    printf("Server says: %s\n", buffer);
    if(!strcmp(buffer, "QUIT\n"))
    {
        printf("Exiting...\n");
        exit(0);
    }

  }
}
void upper_string(char s[]) {
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
}
void performServerTask(int newsockfd)
{
  char buffer[BUF_LEN];
  int len;
  while(1)
  {
    printf("Server waiting....\n");
    len = read(newsockfd, buffer, BUF_LEN);
    printf("Client said: %s\n", buffer);
    upper_string(buffer);
    write(newsockfd, buffer, BUF_LEN);
    if(!strcmp(buffer, "QUIT\n"))
    {
        printf("Exiting...\n");
        exit(0);
    }
  }

}

void terminateSocket(int sockfd){
  close(sockfd);
}
