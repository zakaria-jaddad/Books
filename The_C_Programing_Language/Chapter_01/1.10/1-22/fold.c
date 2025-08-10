#include <stdio.h>
#include "../header/tab.h"

void formate_line(char line[], char new_line[]);

int ncolumn = 14;

int main(void)
{
  char s[MAXLENGTH];

  while (get_user_line(s, MAXLENGTH) == 0)
  {
    char formated_line[MAXLENGTH];
    formate_line(s, formated_line);
    print_line(formated_line);
  }
}

void formate_line(char line[], char new_line[])
{
  int i, last_space, no_space_flag;

  last_space = -1; // -1 means no space before
  i = no_space_flag = 0;

  while (line[i] != '\n')
  {
    if (i % ncolumn == 0 && i != 0)
    {
      if (line[i] == ' ')
      {
        new_line[i] = '\n';
      }
      else
      {
        if (last_space != -1)
        {
          new_line[last_space] = '\n';
        }
        else
        {
          no_space_flag = -1;
        }
        new_line[i] = line[i];
      }
    }
    else
    {
      if (line[i] == ' ')
      {
        if (no_space_flag == -1) 
        {
          new_line[i] = '\n';
          no_space_flag = 0;
        }
        else {
          new_line[i] = line[i];
        }
        last_space = i;
      }
      else {
        new_line[i] = line[i];
      }
    }
    ++i;
  }
  new_line[i] = '\n';
  new_line[i + 1] = '\0';
}