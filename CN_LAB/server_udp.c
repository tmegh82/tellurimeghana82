#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>


#define PORT 8080
#define MAXLINE 1024


int main()
{
	int sockfd;
	char buffer[MAXLINE];
	char *hello = "Hello from server";
	
	struct sockaddr_in servaddr,clientaddr;
	
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&servaddr, 0 , sizeof(servaddr));
	memset(&clientaddr, 0 , sizeof(clientaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	if(bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("Bind Failed");
		exit(EXIT_FAILURE);
	}

	int len,n;
	 
//	printf("Is it receiving\n");

	n = recvfrom(sockfd, (char *)buffer, MAXLINE, 0 , ( struct sockaddr *) &clientaddr,&len);
	 buffer[n] = '\0';
	
	 
	 printf("Client: %s\n", buffer);
	 
	 sendto(sockfd, (const char*)hello, strlen(hello), 0, (const struct sockaddr*)&clientaddr, len);
	 
	 printf("Hello message sent\n");
	 
	 return(0);

}
