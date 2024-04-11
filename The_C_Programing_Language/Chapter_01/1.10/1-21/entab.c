/*
  Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
  number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
  When either a tab or a single blank would suffice to reach a tab stop, which should be given
  preference?
 */

#include <stdio.h>
#include "../header/tab.h"

void remove_line_blanck(char s[], char formated_line[]);

int nspaces = 3;

int main(void)
{
  char s[MAXLENGTH];
  while (get_user_line(s, MAXLENGTH) == 0)
  {
    char formated_line[MAXLENGTH];
    remove_line_blanck(s, formated_line);
    print_line(formated_line);
  }
  return 0;
}

void remove_line_blanck(char line[], char new_line[])
{
  int current_index, new_line_index, tabs_counter, space_counter;
  current_index = new_line_index = tabs_counter = space_counter = 0;

  while (line[current_index] != '\n')
  {
    if (space_counter <= nspaces)
    {
      if (line[current_index] == '\t')
      {
        new_line[new_line_index] = line[current_index];
        ++new_line_index;
        ++tabs_counter;
      }
      else if (line[current_index] == ' ' && tabs_counter > 0)
      {
        int space_index = new_line_index;
        while (new_line_index < space_index + tabs_counter)
        {
          new_line[new_line_index] = '\t';
          ++new_line_index;
        }
        space_counter =  tabs_counter = 0;
      }
      else
      {
        new_line[new_line_index] = line[current_index];
        ++new_line_index;
      }
    }
    else
    {
      new_line[new_line_index] = line[current_index];
      ++new_line_index;
    }
    ++current_index;
  }
  new_line[new_line_index] = '\n';
  new_line[new_line_index + 1] = '\0';
}
