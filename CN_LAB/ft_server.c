
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include<ctype.h> 
#define PORT 8080

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address,clientaddr;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
     
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {			
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
     
   
    /*if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {			
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }*/
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
   
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
	int len = sizeof(clientaddr);

    if ((new_socket = accept(server_fd, (struct sockaddr *)&clientaddr, 
                       &len))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

	FILE *fp;
	int ch = 0;
        fp = fopen("glad_received.c" , "a");
	
	int words;
	
	read(new_socket , &words , sizeof(int));
	

	while(ch!=words)
	{
	read(new_socket , buffer , 255);
	fprintf(fp, "%s ", buffer);
	ch++;
	}


	printf("The file has been successfully received\n");
	fclose(fp);
	
  /*  valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );
    //tsend(new_socket , hello , strlen(hello) , 0 );
    //printf("Hello message sent\n");
    send(new_socket,buffer, strlen(hello),0);
    printf("Return msg from server\n");

   //  valread = read( new_socket , buffer, 1024);
    //printf("%s\n",buffer );
*/    
return 0;
}

