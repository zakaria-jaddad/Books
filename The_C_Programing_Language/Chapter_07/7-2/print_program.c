
#include <stdio.h>
#include <unistd.h>

#define MAX_LEN 100

int valid_arguments(size_t argc, char **argv);
int is_ascii(int);

int is_octal = 0;

int main(int argc, char **argv)
{
  if (!valid_arguments(argc, argv))
  {
    puts("ERROR: invaid number of arguments");
    return -1;
  }
  int c;

  while ((c = getc(stdin)) != EOF)
  {
    if (is_ascii(c))
    {
      if (c == '\n')
        c = ' ';
      putc(c, stdout);
    }
    else
    {
      if (is_octal)
        printf("\\%o", c);
      else
        printf("\\%x", c);
    }
  }
  putc('\n', stdout);
  return 0;
}

int valid_arguments(size_t argc, char **argv)
{
  // check number of arguments
  if (argc != 2)
    return 0;

  // check second argument either -o or -x
  char *second_argument = argv[1];
  if (second_argument[0] == '-')
  {
    if (second_argument[1] == 'o')
    {
      is_octal = 1;
      return 1;
    }
    else if (second_argument[1] == 'x')
    {
      is_octal = 0;
      return 1;
    }
  }
  return 0;
}

int is_ascii(int c) { return (c > 127) ? 0 : 1; }
