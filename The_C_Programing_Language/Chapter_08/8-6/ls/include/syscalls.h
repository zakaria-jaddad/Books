#ifndef SYSCALLS_H
#define SYSCALLS_H

#include "dirent.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef DIRSIZ
#define DIRSIZ 14
#endif
/* directory entry */
struct direct
{
  ino_t d_ino;         /* inode number */
  char d_name[DIRSIZ]; /* long name does not have '\0' */
};

#define NAME_MAX 14
#define MAX_PATH 1024

/* portable directory entry */
typedef struct
{
  long ino;                /* inode number */
  char name[NAME_MAX + 1]; /* name + '\0' terminator */
} Dirent;

/* minimal DIR: no buffering, etc */
typedef struct
{
  int fd;   /* file descriptor for the directory */
  Dirent d; /* the directory entry */
} MY_DIR;

void fsize(char *);
void dirwalk(char *, void (*fcn)(char *));
int my_stat(char *, struct stat *);

MY_DIR *my_opendir(char *);
void my_closedir(MY_DIR *dp);
Dirent *my_readdir(MY_DIR *);

#endif
