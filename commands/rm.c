#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc , char  **argv){

  int count;
  
  if(argc < 2 || strcmp(argv[1],"--help") == 0){
    printf("Usage: %s file1 ...\n",argv[0]);
    exit(1);
  }
  
  count= argc -1;
  while(count >0){
    if((unlink(argv[count]) == -1))
      printf("%s: cannot remove %s: %s\n",argv[0],argv[count],strerror(errno));
    count--;
  }

  return 0;
}
