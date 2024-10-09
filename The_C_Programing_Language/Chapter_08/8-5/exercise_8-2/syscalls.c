#include "syscalls.h"
#include "time.h"
#include <time.h>

MY_FILE *ft_fopen(char *name, char *mode)
{
  int fd;
  MY_FILE *fp;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return (NULL);
  for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
    if (fp->flag._READ == 0 || fp->flag._WRITE == 0)
      break;
  if (fp > _iob + OPEN_MAX)
    return (NULL);
  if (*mode == 'w')
    fd = creat(name, PERMS);
  else if (*mode == 'a')
  {
    if ((fd = open(name, O_WRONLY, 0)) == -1)
      fd = creat(name, PERMS);
    lseek(fd, (long) 2, 0);
  }
  else
  {
    if ((fd = open(name, O_RDONLY, 0)) == -1)
      return (NULL);
  }
  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL;
  fp->flag._EOF = 0;
  fp->flag._ERR = 0;
  fp->flag._WRITE = (*mode == 'w') ? (unsigned char) 1 : (unsigned char) 0;
  fp->flag._READ = (*mode == 'r') ? (unsigned char) 1 : (unsigned char) 0;
  return (fp);
}

/* _fillbuf: allocate and fil input buffer with fields */
int _fillbuf(MY_FILE *fp)
{
  int bufsize;

  if (fp->flag._READ == 0 || fp->flag._EOF == 1 || fp->flag._ERR == 1)
    return EOF;
  bufsize = (fp->flag._UNBUF == 1) ? 1 : BUFSIZ;

  if (fp->base == NULL)
  {
    fp->base = (char *) malloc(bufsize);
    if (fp->base == NULL)
      return EOF;
  }
  fp->ptr = fp->base;
  fp->cnt = read(fp->fd, fp->ptr, bufsize);
  if (--(fp->cnt) < 0)
  {
    if (fp->cnt == -1)
      fp->flag._EOF = -1;
    else
      fp->flag._ERR = -1;
    fp->cnt = 0;
    return EOF;
  }
  return (unsigned char) *(fp->ptr)++;
}

/* stdin, stdout, stderr */
MY_FILE _iob[OPEN_MAX] = {
    {0, (char *) 0, (char *) 0, {1, 0, 0, 0, 0}, 0},
    {0, (char *) 0, (char *) 0, {0, 1, 0, 0, 0}, 1},
    {0, (char *) 0, (char *) 0, {0, 1, 1, 0, 0}, 2},
};

int main(void)
{
  clock_t start = clock();
  MY_FILE *file_p;

  if ((file_p = ft_fopen("syscalls.c", "r")) == NULL)
  {
    write(1, "Error: could not open the file.\n", 33);
    return EXIT_FAILURE;
  }
  char c;
  while ((c = getc(file_p)) != EOF)
  {
    write(1, &c, 1);
  }
  clock_t end = clock();
  double time_spent = (double) (end - start) / CLOCKS_PER_SEC;
  printf("\nThe run time is %f\n", time_spent);
  return EXIT_SUCCESS;
}
