#include "../syscalls.h"
#include <cstdio>
#include <stdarg.h>
#include <stdio.h>
#include <sys/fcntl.h>

#define PERMS 0666 /* RW for owner, group and others */

void error(char *, ...);

/* cp: copy f1 to f2 */
int main(int argc, char **argv)
{
  char buf[BUFSIZ];

  int f1, f2, n;
  if (argc != 3)
    error("Usage: cp from to");
  if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
    error("cp: can't open %s", argv[1]);
  if ((f2 = creat(argv[2], PERMS)) == -1)
    error("cp: can't creat %s, mode %03c", argv[2], PERMS);
  while ((n = read(f1, buf, BUFSIZ)) > 0)
  {
    if (write(f2, buf, n) != n)
      error("cp: write error on file %s", argv[2]);
  }
  return (EXIT_SUCCESS);
}

void error(char *fmt, ...)
{
  va_list args;

  va_start(args, fmt);
  fprintf(stderr, "error: ");
  vprintf(stderr, args);
  fprintf(stderr, "\n");
  va_end(args);
  exit(1);
}
