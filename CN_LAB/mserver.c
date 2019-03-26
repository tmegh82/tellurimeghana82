
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include<ctype.h> 
#define PORT 8080



int main(int argc, char *argv[])
{
	int server_fd,new_socket;
	 char buffer[1024] = {0};
    char *hello = "Hello from server";
	
	struct sockaddr_in servaddr,clientaddr;
	
	if((server_fd = socket(AF_INET, SOCK_STREAM,0))==0)
	{
		perror("socket creation failed");
		exit(EXIT_FAILURE);

		}
	
	
	memset(&servaddr, 0 , sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);

	if(bind(server_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("Bind Failed");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0)
  	  {
  	      perror("listen");
  	      exit(EXIT_FAILURE);
  	  }
  
	int clilen = sizeof(clientaddr);
	  if ((new_socket = accept(server_fd, (struct sockaddr *)&clientaddr, &clilen))<0)
	    {
        	perror("accept");
        	exit(EXIT_FAILURE);
    		}
	
	  read( new_socket , buffer, 1024);
  	  printf("%s\n",buffer );
     //send(new_socket,buffer, strlen(hello),0);
     //printf("Return msg from server\n");

    send(new_socket , hello , strlen(hello) , 0);
    printf("Hello message sent\n");
	return 0;
}


