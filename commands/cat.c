// cat using system calls : minimal

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>


#define BUF_SIZE 1024

int main(int argc, char **argv){


  int count = argc-1;
  int fd;
  size_t total_read;
  char buffer[BUF_SIZE];
  
  if(argc < 2){

      printf("%s: Missing file operand\nTry %s --help for more information\n", argv[0], argv[0]);
      exit(1);
  }
  
  if(strcmp(argv[1],"--help") == 0){
    printf("Usage: %s FILE\n", argv[0]);
    exit(1);
  }
  while(count > 0){

    fd = open(argv[count], O_RDONLY);
    while((total_read = read(fd, buffer, BUF_SIZE)) >0)
      if(write(STDOUT_FILENO, buffer, total_read) != total_read)
	printf("Couldnt write whole buffer");
    
    if(total_read ==-1)
      perror(" ");
    if(close(fd) == -1)
      perror(" ");
    
    count--;
  }
  
  
  return 0;
}
