#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<errno.h>

#define SIZE 1024
#define RED "\x1b[31m"
#define WHITE "\x1b[37m"
#define COLOR_RESET   "\x1b[0m"

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
	printf(WHITE "%-15s%s\n" RED ,"regular:", dir->d_name );
      else if(dir->d_type == DT_DIR && strcmp(dir->d_name,"..") != 0 && strcmp(dir->d_name,".") != 0){
	printf("\n%-15s%s%s\n","directory:", RED, dir->d_name);
	  walk_directory(dir->d_name);
	  printf("\n");
      }
       
      //printf("\n");
    }
    closedir(d);
  }
}
