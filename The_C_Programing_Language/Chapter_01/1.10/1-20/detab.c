#include <stdio.h>
#include "../header/tab.h"

// if you want to run the program use the makefile command.

// Global varibales
int ntabs = 3;

void remove_line_tabs(char s[], char fomrated_line[]);

int main(void)
{
  char s[MAXLENGTH];
  while (get_user_line(s, MAXLENGTH) == 0)
  {
    char formated_line[MAXLENGTH];
    remove_line_tabs(s, formated_line);
    print_line(formated_line);
  }
}


void remove_line_tabs(char line[], char new_line[])
{
  int i, j, space_counter, tabs_counter;
  i = j = space_counter = tabs_counter = 0;

  while (line[i] != '\n')
  {
    if (tabs_counter <= ntabs)
    {
      // if current line is space 
      if (line[i] == ' ')
      {
        new_line[j] = ' ';
        ++space_counter;
        ++j;
      }
      else if (line[i] == '\t')
      {
        if (space_counter > 0)
        {
          int tab_index = j;
          while (j < tab_index + space_counter)
          {
            new_line[j] = ' ';
            ++j;
          }
        }
        // no space count 
        else
        {
          new_line[j] = '\0';
          ++j;
        }
        space_counter = 0;
        ++tabs_counter;
      }
      // if current line is char and not a tab nor a space 
      else
      {
        new_line[j] = line[i];
        ++j;
      }
    }
    else
    {
      new_line[j] = line[i];
      ++j;
    }
    ++i;
  }
  new_line[j] = '\n';
  new_line[j + 1] = '\0';
}
