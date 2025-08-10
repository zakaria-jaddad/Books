/*
  Exercise 1-17. Write a program to print all input lines that are longer than 80 characters
  when user write an input  after they press new line '\n'
  get it and check if that line has more than 80 lines
  store it in the mu_string array
  and using for loop print it
 */
#include <stdio.h>

int get_user_line(char s[], int limit);

#define MINLENGTH 80 
#define MAXLENGTH 10000

int main(void)
{
  char my_string[MAXLENGTH];
  int c;
  while (MINLENGTH < get_user_line(my_string, MAXLENGTH))
  {
    int i;
    i = 0;
    while (my_string[i] != '\0')
    {
      printf("%c", my_string[i]);
      ++i;
    }
  }
}

int get_user_line(char s[], int limit)
{
  int c, i, j;
  j = i = 0;
  while ((c = getchar()) != '\n')
  {
    if (i < limit - 2)
    {
      s[j] = c;
      ++j;
    }
    ++i;
  }
  s[j] = '\n';
  s[j + 1] = '\0';
  return i;
}