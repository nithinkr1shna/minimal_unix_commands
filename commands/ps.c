#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<ctype.h>

#define SIZE 1024
void get_pid_pname(char *);

int main(int argc, char **argv){

  int digit;
  DIR  *d;
  char path[SIZE];
  struct dirent *dir;
  d = opendir("/proc");
  while((dir = readdir(d)) != NULL){
    if(dir->d_type == DT_DIR && strcmp(dir->d_name, "..") != 0 && strcmp(dir->d_name, ".") != 0){
      digit = dir->d_name[0];
      
      if(isdigit(digit)){
	 
         sprintf(path, "/proc/%s/comm",dir->d_name);
         get_pid_pname(path);
	 printf("%s\n", dir->d_name);
      }
      
    }
  }

  return 0;
}

void get_pid_pname(char *name){

  
  char buffer[1024];
  int fd;
  size_t nread;
 
  
  fd = open(name, O_RDONLY);
  if(fd == -1)
    perror("error ");
  
  while((nread = read(fd, buffer, SIZE)) > 0)
    if(strcmp(buffer, "\n") !=0)
      write(STDOUT_FILENO, buffer, nread);

  
  if(close(fd) == -1)
    perror(" ");
  
}
