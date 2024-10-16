#include "./include/syscalls.h"

/* opendir: open a directory for readdir calls */
MY_DIR *my_opendir(char *dirname)
{
  int fd;
  struct stat stbuf;

  MY_DIR *dp;

  if ((fd = open(dirname, O_RDONLY, 0)) == -1 || fstat(fd, &stbuf) == -1 ||
      (stbuf.st_mode & S_IFMT) != S_IFDIR ||
      (dp = (MY_DIR *) malloc(sizeof(MY_DIR))) == NULL)
    return NULL;
  dp->fd = fd;
  return dp;
}
