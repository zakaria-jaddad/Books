#include <stdio.h>
#include <stdlib.h>

/* HEY: run ./print input-1.txt input-2.txt */
int main(int argc, char **argv)
{
  FILE *fp;
  size_t page_count;
  void filecopy(FILE *, FILE *);
  char *program_name = argv[0]; /* program name for errors */
  char *file_name;

  page_count = 1;
  if (argc == 1) /* no argc: copy standard input */
  {
    fprintf(stderr, "%s: invalid arguments\n", program_name);
    exit(EXIT_FAILURE);
  }
  while (--argc > 0)
  {
    file_name = *++argv;
    if ((fp = fopen(file_name, "r")) == NULL)
    {
      fprintf(stderr, "cat: cant\'t open %s\n", *argv);
      return -1;
    }
    else
    {
      printf("[%zu] ======= %s =======\n", page_count, file_name);
      filecopy(fp, stdout);
      fclose(fp);
    }
    page_count++;
  }
  if (ferror(stdout))
  {
    fprintf(stderr, "%s: error writing stdout\n", program_name);
    exit(2);
  }
  exit(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
  int c;

  while ((c = getc(ifp)) != EOF)
    putc(c, stdout);
}
