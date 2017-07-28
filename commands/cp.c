#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>


#define BUF_SIZE 1024

int main(int argc , char **argv){

  int inputfd, outputfd, flags_open;
  mode_t filepermissions;
  ssize_t total_read;
  char buffer[BUF_SIZE];

  if(argc < 2 || argc !=3 || strcmp(argv[1],"--help") ==0){ 

    printf("Usage: %s file1 file2\n", argv[0]);
    exit(1);
  }

  
  inputfd = open(argv[1],O_RDONLY); // creating input file descriptor 

  if(inputfd == -1) 
    perror("Error in opening file\n");

  
  flags_open = O_CREAT | O_WRONLY | O_TRUNC ;  //flags for opening new file
  filepermissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; //creating file permissions
  outputfd = open(argv[2], flags_open, filepermissions); // creating file descriptor for utput file
  
  if(outputfd == -1)
    perror("Error in opening file");

  //writing to output file;
  while((total_read = read(inputfd, buffer, BUF_SIZE)) > 0)
    if(write(outputfd, buffer, total_read) != total_read) //if not able to write whole of the buffer
      perror("Couldn't write whole buffer\n");

  if(total_read == -1)
    perror("Error in read\n");
  

  if(close(inputfd) == -1) // closing input fd
    perror("Error in closing");
  if(close(outputfd) == -1) // closing output fd
    perror("Error in closing");
  
  
  return 0;
  
}
