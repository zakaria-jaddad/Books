#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void error(char *, ...);
void filecopy_to_stdout(char *);

/* HEY: run ./cat input-1.txt input-2.txt */
/* cat program using read, write, open and close */
/* cat: concatenate files, exercise */
int main(int argc, char **argv)
{
  int n;
  char buf[BUFSIZ];

  if (argc == 1)
  {
    while ((n = read(STDIN_FILENO, buf, BUFSIZ)) > 0)
      if (write(STDOUT_FILENO, buf, n) != n)
        error("cat: write error");
    exit(EXIT_SUCCESS);
  }
  while (--argc > 0)
    filecopy_to_stdout(*++argv);
  exit(EXIT_SUCCESS);
}

void filecopy_to_stdout(char *filename)
{
  char buf[BUFSIZ];

  int fd, n;
  if ((fd = open(filename, O_RDONLY, 0)) == -1)
  {
    error("cat: can't open %s", filename);
    exit(EXIT_FAILURE);
  }
  while ((n = read(fd, buf, BUFSIZ)) > 0)
    if (write(STDOUT_FILENO, buf, n) != n)
      error("cat: write error");
  close(fd);
}

void error(char *fmt, ...)
{
  va_list args;

  va_start(args, fmt);
  fprintf(stderr, "ERROR: ");
  vfprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  exit(EXIT_FAILURE);
}
