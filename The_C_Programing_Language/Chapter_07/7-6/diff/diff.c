#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100

int main(int argc, char **argv)
{
  char *filename[] = {argv[1], argv[2]};
  FILE *fp1;
  FILE *fp2;
  char s1[MAX_LINE_LEN];
  char s2[MAX_LINE_LEN];

  if (argc != 3)
  {
    fprintf(stderr, "Invalid number of arguments\n");
    exit(-1);
  }
  fp1 = fopen(filename[0], "r");
  fp2 = fopen(filename[1], "r");
  while (fgets(s1, MAX_LINE_LEN, fp1) != NULL &&
         fgets(s2, MAX_LINE_LEN, fp2) != NULL)
  {
    if (strcmp(s1, s2) != 0)
    {
      fprintf(stdout, "%s", s1);
      fprintf(stdout, "==================\n");
      fprintf(stdout, "%s", s2);
    }
  }
  return (0);
}
