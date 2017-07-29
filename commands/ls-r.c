#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<errno.h>

#define SIZE 1024
#define RED "\x1b[31m"
#define WHITE "\x1b[37m"

void walk_directory(char *str);
int main(int argc, char **argv){

  
  
  char cwd[SIZE];
  getcwd(cwd, sizeof(cwd));
  walk_directory(cwd);
 
  return 0;
}


void walk_directory(char *str){

    DIR *d;
 
   d = opendir(str);
   struct dirent *dir;
   if(d){

    while((dir = readdir(d)) != NULL){

     
      if(dir->d_type != DT_DIR)
	  printf("%s%s", WHITE, dir->d_name);
      else if(dir->d_type == DT_DIR && strcmp(dir->d_name,"..") != 0 && strcmp(dir->d_name,".") != 0){
	printf("%s%s", RED, dir->d_name);
	  walk_directory(dir->d_name);
	
      }
       
      printf("\n");
    }
    closedir(d);
  }
}
