### Basic unix commands: minimal

This repository contains some unix commands that are implemented with system calls. This commands are minimal versions of the original commands.

##### cat:
This is a toy version of cat command. This works with read and write system calls.The program reads the file contents and outputs it to stdout.

##### cp:
This toy implementation of cp command copies file contents from one file to another.

##### ls and ls-r:
These are list and list recursive commands.ls-r uses a function walk_directory to list all the files under under a directory using the dirent header. 

##### mkdir:
Simplest implementation of make directory command.

##### mv:
This is the same as unix mv command. This moves the contents of one file to another. This command can be used to rename a file. This implementation uses unlink system call to delete a name and possibly the file it refers to.

##### ps:
This is a toy version of unix process status command. 

##### rm:
The rm command uses unlink system call to deete a name and possibly the file it refers to.

##### rmdir:
rmdir can use used to remove a empty directory

##### tee:
This is a simple unix tee command implementaion, this program reads standard input and writes to both output stream and a file.

##### touch:
Creates a file with with

    flags : O_RDWR | O_CREAT
    permissions: S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
    
    
The usage of each command can be found out by passing "--help" as a command line argument.
