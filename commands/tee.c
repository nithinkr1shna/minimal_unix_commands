#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<getopt.h>

#ifndef BUFFSIZE
#define BUFFSIZE 1024
#endif

void to_stdout_cpy(char *filename, int flag);
int main(int argc , char **argv){

  int flag=1, count =argc-1;

  if(argc <2){
    flag=0;
    while(1)
      to_stdout_cpy(argv[0],flag);
  }else{
    
    while(count >0){
       to_stdout_cpy(argv[count], flag);
       count--;
    }
   }
}


 
void to_stdout_cpy(char *filename, int flag){

  ssize_t n_read, file_write;
  int fd,openFlags;
  char buff[BUFFSIZE];
  mode_t filemode;
  static int count =0;
  printf("%s\n",filename);
  filemode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
  fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, filemode);
  while((n_read = read(STDIN_FILENO, buff, BUFFSIZE)) > 0){
    if(n_read == -1){

      printf("error cnt read from stdin\n");
      exit(0);
    }
    if(count ==0)
       write(STDOUT_FILENO, buff, n_read);
    
    if(flag == 1){
      write(fd, buff, n_read);
       if(fd  == -1){

	printf("error opening file\n");
	exit(0);
	}
      
    }
	
  }
      
    
  
  if(close(fd)== -1)
    perror(" ");

  count++;
}
