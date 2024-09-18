#include "../includes/header.h"

int file_length(char *file_path)
{
  int c;
  int length = 0;
  FILE *file;
  file = fopen(file_path, "r");
  if (file)
  {
    while ((c = getc(file)) != EOF)
      length++;
    fclose(file);
  }
  return length;
}

char *read_file(char *file_path)
{
  int c;
  int i;
  int length;
  FILE *file;

  i = 0;
  length = file_length(file_path);
  char *file_content = (char *)malloc(sizeof(char) * length + 1);

  file = fopen(file_path, "r");
  if (file)
  {
    while ((c = getc(file)) != EOF)
      file_content[i++] = c;
    file_content[i] = '\0';
    fclose(file);
  }
  return file_content;
}
