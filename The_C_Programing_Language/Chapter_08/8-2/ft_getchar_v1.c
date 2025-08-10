#include "syscalls.h"

/* ft_getchar: unbeffered single character input */
int ft_getchar(void)
{
  char c;
  return (read(0, &c, 1) == 1) ? (unsigned char)c : EOF;
}
