#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>



int main(int argc, char **argv)
{
  struct stat f;
    
    stat(argv[1], &f);
    if (S_ISDIR(f.st_mode)) {
	if (rmdir(argv[1]) < 0) {
	  printf("%s is not empty\n",argv[1]);
	}
    } else {
	printf("%s is not directory\n", argv[1]);
    }
}
