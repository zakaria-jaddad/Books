#include <ctype.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  int hello = printf("%d, %d\n", 10, 20);
  printf("%d\n", hello);

  char *str = argv[0];
  while (*str)
  {
    if (islower(*str))
      putchar(toupper(*str));
    else if (isupper(*str))
      putchar(tolower(*str));
    else
      putchar(*str);
    str++;
  }
  return 0;
}
