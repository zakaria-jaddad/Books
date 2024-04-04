/*
  Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines
 */
#include <stdio.h>

#define MAXLENGTH 300

int get_user_line(char s[], int limit);
void formate_line(char line[], char new_line[]);
void print_line(char line[]);

int main(void)
{
  char line[MAXLENGTH];
  while (get_user_line(line, MAXLENGTH) == 0)
  {
    char formated_line[MAXLENGTH];
    formate_line(line, formated_line);
    print_line(formated_line);
  }
  return 0;
}

int get_user_line(char s[], int limit)
{
  int c, i;
  for (i = 0; i < limit - 2 && (c = getchar()) != '\n'; ++i)
  {
    s[i] = c;
  }
  s[i] = '\n';
  s[i + 1] = '\0';
  return 0;
}

void formate_line(char line[], char new_line[])
{
  int i, j;
  i = j = 0;
  while (line[i] != '\0')
  {
    if (line[i] != ' ' && line[i] != '\t')
    {
      new_line[j] = line[i];
      ++j;
    }
    ++i;
  }
}

void print_line(char line[])
{
  int i;
  i = 0;
  while (line[i] != '\0')
  {
    printf("%c", line[i]);
    ++i;
  }
}