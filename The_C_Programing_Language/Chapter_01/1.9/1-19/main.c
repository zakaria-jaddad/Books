#include <stdio.h>

int get_user_line(char s[], int limit);
void reverse_line(char s[], char reversed_line[], int limit);
void print_line(char line[]);
void new_string(char s[], int limit);

#define MAXLENGTH 300

int main(void)
{
  char s[MAXLENGTH];

  while (get_user_line(s, MAXLENGTH) == 0)
  {
    char reversed_line[MAXLENGTH];
    new_string(reversed_line, MAXLENGTH);
    
    reverse_line(s, reversed_line, MAXLENGTH);
    print_line(reversed_line);
  }
}

int get_user_line(char s[], int limit)
{
  new_string(s, limit);
  int c, i;
  i = 0;

  while (i < limit - 2 && (c = getchar()) != '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\n';
  s[i + 1] = '\0';

  return 0;
}

void reverse_line(char s[], char reversed_line[], int limit)
{

  int i, j;
  j = 0;

  for (i = limit - 2; i >= 0; i = i - 1)
  {
    if (s[i] >= '!' && s[i] <= '~')
    {
      reversed_line[j] = s[i];
      ++j;
    }
  }
  reversed_line[j] = '\n';
  reversed_line[j + 1] = '\0';
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

void new_string(char s[], int limit) {
  for (int i = 0; i < limit; i++)
  {
    s[i] = ' ';
  }
}