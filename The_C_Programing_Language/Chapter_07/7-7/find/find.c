#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000

int my_getline(char *s, int limit);
int check_args(int, char **);

int number = 0;

/* HEY: run ./find -n "hey there" input-1.txt input-2.txt */
int main(int argc, char **argv)
{
  size_t line_number;
  char line[MAX_LINE_LEN];
  char *program_name;
  char *filename;
  FILE *fp;

  program_name = argv[0];
  line_number = 1;
  if (!check_args(argc, argv))
    exit(EXIT_FAILURE);
  if (argc > 3)
  {
    for (int i = 3; i < argc; ++i)
    {
      filename = argv[i];
      fp = fopen(filename, "r");
      if (fp == NULL)
      {
        fprintf(stderr, "%s: can't open file %s.\n", program_name, filename);
        exit(EXIT_FAILURE);
      }
      while (fgets(line, MAX_LINE_LEN, fp) != NULL)
      {
        if (strstr(line, *(argv + 2)) != NULL)
        {
          printf("%s [%zu] | %s", filename, line_number, line);
        }
        line_number++;
      }
      fclose(fp);
    }
    exit(EXIT_SUCCESS);
  }
  filename = "stdin";
  while (fgets(line, MAX_LINE_LEN, stdin) != NULL)
  {
    if (strstr(line, *(argv + 2)) != NULL)
    {
      printf("%s [%zu] | %s", filename, line_number, line);
    }
    line_number++;
  }
  exit(EXIT_SUCCESS);
}

int check_args(int argc, char **argv)
{
  char *program_name;
  int c;

  program_name = argv[0];
  if (argc < 3)
  {
    fprintf(stderr, "Usage: %s [-xn]... PATTERN [FILE]...\n", program_name);
    return (0);
  }
  while (--argc > 0 && (*++argv)[0] == '-')
  {
    while ((c = *++argv[0]))
    {
      switch (c)
      {
      case 'n':
        number = 1;
        break;
      default:
        fprintf(stderr, "%s: illegal optiong -%c", program_name, c);
        return (0);
      }
    }
  }
  return (1);
}
