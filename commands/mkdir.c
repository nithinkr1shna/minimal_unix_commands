// mkdir using fork and execl system call

#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc , char **argv){
 
  int open_flags, count = argc-1,fd;
  mode_t filepermissions;

  if(argc<2){
     printf("%s: Missing file operand\nTry %s --help for more information\n",argv[0],argv[0]);
     exit(1);
  }
  if(strcmp(argv[1],"--help") ==0){
    printf("Usage %s DIRECTORY\n",argv[0]);
    exit(1);
  }

  while(count >0){
    if(fork() !=0)
      wait((int *)0);
    else{

 
       execl("/bin/mkdir","mkdir",argv[count], (char*)NULL);
       perror(" ");
      
    }
    count--;
    
  }

  
  return 0;
}
