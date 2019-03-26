
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include<ctype.h> 
#include<unistd.h>
#include <sys/types.h>
#include<netdb.h>
#include<netinet/in.h>
#define PORT 8080		
 

int main(int argc, char const *argv[])
{
 
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char *hello2 = "hello2 from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {	
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
   /* if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }*/
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

	bzero(buffer,250);
	
	FILE *f;
	int words = 0;

	char c;
	
	f = fopen("echo_client.c" , "r");
	
	while((c=getc(f))!=EOF)
	{
		fscanf(f, "%s", buffer);
		if(isspace(c) || c=='\t')
			++words;
		}
	write(sock , &words, sizeof(int));
	rewind(f);

	char ch;

	while(ch!=EOF)
	{
		fscanf(f ,"%s", buffer);
		write(sock, buffer , 255);
		ch = fgetc(f);
		}
	
	//printf("%s",buffer);
	printf("The file has been successfully sent\n");


 /*   send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    
     //send(sock , hello2 , strlen(hello) , 0 );
    //printf("Hello2 message sent\n");
 */   
    return 0;
}
