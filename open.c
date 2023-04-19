#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define f_size 8192

int main()
{
  int fd;
  char buf[f_size]={"Priyanka Linix kernel driver priya kriya"};

  fd=open("file1.txt",O_WRONLY|O_CREAT,777);
  if(fd==-1)
  {
    perror("open");
    exit(1);
  }

  if(write(fd,buf,f_size)==-1)
  {
    perror("write");
    exit(1);
  }

  if(lseek(fd,f_size/2,SEEK_SET)==-1)
  {
    perror("lseek");
    exit(1);
  }

  if(write(fd,"\0",1)==-1)
  {
    perror("write");
    exit(1);
  }
  
  if(close(fd)==-1)
  {
    perror("close");
    exit(1);
  }

 return 0;
}
