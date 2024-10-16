#include "./include/syscalls.h"
#include <stdio.h>

/* print file name */
/* HEY: run ./main test */
int main(int argc, char **argv)
{
  if (argc == 1)
    fsize(".");
  else
    while (--argc > 0)
      fsize(*++argv);
  return (0);
}

/* fsize: print the name of file "name" */
void fsize(char *name)
{
  struct stat stbuf;

  if (stat(name, &stbuf) == -1)
  {
    fprintf(stderr, "fsize: can't access %s\n", name);
    return;
  }
  if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
    dirwalk(name, fsize);
  printf("%8lld %s\n", stbuf.st_size, name);
}

/* dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *))
{
  char name[MAX_PATH];
  Dirent *dp;
  MY_DIR *dfd;

  if ((dfd = my_opendir(dir)) == NULL)
  {
    fprintf(stderr, "dirwalk: can't open %s\n", dir);
    return;
  }
  while ((dp = my_readdir(dfd)) != NULL)
  {
    printf("%s", dp->name);
    if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, ".."))
      continue; /* skip self and parent */
    if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
      fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->name);
    else
    {
      sprintf(name, "%s/%s", dir, dp->name);
      (*fcn)(name);
    }
  }
  my_closedir(dfd);
}
// this is not working and i don't know why?
