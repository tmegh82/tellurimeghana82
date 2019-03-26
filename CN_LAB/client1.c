#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>

#define PORT 8080

int main(int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_in address;
	char *hello = "Hello from Client";
	char buffer[1024] = {0};
	
	memset(&address, 0 , sizeof(address));

	if((sockfd = socket(AF_INET, SOCK_STREAM,0))<0)
	{
		perror("Socket Creation Failed\n");
		exit(EXIT_FAILURE);
		}

	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);
	address.sin_addr.s_addr = INADDR_ANY;
	
	
	if(connect(sockfd, (struct sockaddr*)&address, sizeof(address))<0)
	{
		perror("Connection Failed\n");
		exit(EXIT_FAILURE);	
		}

	send(sockfd, hello, strlen(hello),0);
	printf("Hello message sent from CLient\n");
	
	read(sockfd, buffer, 1024);
	printf("%s\n",buffer);

	return(0);
	}




