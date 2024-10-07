#include "syscalls.h"

/* ft_getchar: unbeffered single character input */
int ft_getchar(void)
{
  static char buf[BUFSIZ];
  static char *bufp;
  static int n = 0;

  if (n == 0)
  { /* buffer is empty */
    n = read(0, buf, sizeof buf);
    bufp = buf;
  }
  return ((--n >= 0) ? (unsigned char)*bufp++ : EOF);
}
