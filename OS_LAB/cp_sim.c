#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>


#define buffer_size 50
int main()
{
 int fd[2];
 int fd1=open("name.txt",O_RDWR | O_CREAT);
 int fd2=open("cp_simulation_2.txt", O_RDWR | O_CREAT);
 int nb;
 char buffer[buffer_size];

 pid_t pid;

 pipe(fd);
 
 pid=fork();
 

 if(pid==0)
 {
  close(fd[0]);
  dup2(fd[1],1);
  execlp("cat","cat","name.txt",NULL);
  close(fd1);
  close(fd[1]);
 }

 else if(pid>0)
 {
  close(fd[1]);
  int f2=dup2(fd[0],0);
  
  while((nb=read(f2,buffer,buffer_size))>0)
    write(fd2,buffer,sizeof(buffer));
  close(fd2);
  close(fd[0]);  
 }


 return(0);
}
