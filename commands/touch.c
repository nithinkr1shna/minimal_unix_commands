//touch using open system call

#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc , char **argv){

  int count = argc-1;
  mode_t filepermissions;
  int open_flags, fd;

  if(argc<2 ){
    printf("%s: Missing file operand\nTry %s --help for more information\n",argv[0],argv[0]);
    exit(1);
  }
  if(strcmp(argv[1],"--help")== 0){
    printf("Usage %s FILE\n",argv[0]);
    exit(1);
  }
  
  open_flags = O_RDWR | O_CREAT;
  filepermissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
  while(count > 0){

    fd = open(argv[count], open_flags, filepermissions );
    if(fd == -1)
      printf("%s: cannot touch%s: %s\n",argv[0], argv[count],strerror(errno));
    count--;
    
  }

  return 0;
  
}
