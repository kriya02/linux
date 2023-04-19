#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
  int fd,ret,ret1;
  char buf[100]={'0'};

  fd = open("linux.txt", O_CREAT | O_RDWR, 0644);
  if(fd==-1)
  {
   perror("open");
   exit(1);
  }

  ret = write(fd, "priyanka", 8);
  printf("return: %d\n", ret);
  if(ret==-1)
  {
   perror("write");
   exit(1);
  }

  lseek(fd, 0, SEEK_SET);

  ret1 = read(fd, buf, 100);
  printf("return: %d\n", ret1);
  if(ret1==-1)
  {
   perror("read");
   exit(1);
  }

  printf("READ: %s\n", buf);

  close(fd);

  return 0;
}

