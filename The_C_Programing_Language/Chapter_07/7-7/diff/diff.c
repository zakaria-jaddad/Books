#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100

/* HEY: run ./diff input-1.txt input-2.txt */
int main(int argc, char **argv)
{
  char *program_name;
  char *filename[] = {argv[1], argv[2]};
  FILE *fp1;
  FILE *fp2;
  char s1[MAX_LINE_LEN];
  char s2[MAX_LINE_LEN];
  size_t line_number;
  size_t line_length;

  line_number = 1;
  program_name = argv[0];
  if (argc != 3)
  {
    fprintf(stderr, "Invalid number of arguments\n");
    exit(-1);
  }
  fp1 = fopen(filename[0], "r");
  if (fp1 == NULL)
  {
    fprintf(stderr, "%s: can't open file %s.\n", program_name, filename[0]);
    exit(EXIT_FAILURE);
  }
  fp2 = fopen(filename[1], "r");
  if (fp2 == NULL)
  {
    fprintf(stderr, "%s: can't open file %s.\n", program_name, filename[1]);
    exit(EXIT_FAILURE);
  }
  while (fgets(s1, MAX_LINE_LEN, fp1) != NULL &&
         fgets(s2, MAX_LINE_LEN, fp2) != NULL)
  {
    if (strcmp(s1, s2) != 0)
    {
      printf("%s [%zu] -> %s", filename[0], line_number, s1);
      fclose(fp1);
      line_length = (strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2);
      for (int i = 0; i < line_length; ++i)
        printf(">");
      printf("\n");
      printf("%s [%zu] -> %s", filename[1], line_number, s2);
      fclose(fp2);
      break;
    }
    line_number++;
  }
  exit(EXIT_SUCCESS);
}
