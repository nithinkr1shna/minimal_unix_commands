#include <dirent.h>     
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include<string.h>


#define NORMAL "\x1b[0m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"

struct linux_dirent {

  long d_ino;
  off_t d_off;
  unsigned short d_reclen;
  char  d_name[];
  
};

void ls(int , char**);

#define BUF_SIZE 1024


int  main(int argc, char *argv[]){
     ls(argc, argv);

}
void ls(int argc, char **argv){
    int fd, nread;
    char buf[BUF_SIZE];
    struct linux_dirent *d;
    int bpos;
    char d_type;

    fd = open(argc > 1 ? argv[1] : ".", O_RDONLY | O_DIRECTORY);
    if (fd == -1)
       perror(" ");

    for ( ; ; ) {
        nread = syscall(SYS_getdents, fd, buf, BUF_SIZE);
         if (nread == -1)
           perror(" ");

         if (nread == 0)
             break;
               
         for (bpos = 0; bpos < nread;) {
               d = (struct linux_dirent *) (buf + bpos);
               d_type = *(buf + bpos + d->d_reclen - 1);
               printf("%-10s",(d_type == DT_DIR)? "directory": 
			(d_type == DT_REG) ? "regular":"???");
              
	       printf("%s\n",  d->d_name); 
               bpos += d->d_reclen;
               
               
               }
           }

           exit(EXIT_SUCCESS);
       }
