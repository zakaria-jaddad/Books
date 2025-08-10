#include <stdio.h>
#include "../header/tab.h"

int get_file_input(char s[], int limit);
void remove_comments(char line[], char new_line[]);

int main(void)
{
  //  get file input of size MAXLENGHT
  char s[MAXLENGTH];
  get_file_input(s, MAXLENGTH);

  // remove comments
  char formated_input[MAXLENGTH];
  remove_comments(s, formated_input);

  // print new file input witout any comment
  print_line(formated_input);
  return 0;
}

void remove_comments(char line[], char new_line[])
{
  int i, is_single_comment, is_multiple_comment, new_line_index;
  is_single_comment = is_multiple_comment = -1;

  for (i = new_line_index = 0; line[i] != '\0'; ++i)
  {
    if (is_single_comment == -1 && is_multiple_comment == -1) {
      // if single line comment
      if (line[i] == '/' && line[i + 1] == '/') {
        is_single_comment = i;
      }
      // if mulitple line comment detected
      else if (line[i] == '/' && line[i + 1] == '*') {
        is_multiple_comment = i;
      }
      else {
        new_line[new_line_index] = line[i];
        ++new_line_index;
      }
    }
    else {
    // if end of mulitple line comment
      if (line[i - 1] == '*' && line[i] == '/')
      {
        is_multiple_comment = -1;
      }
      else if (line[i] == '\n' || line[i] == '\0')  {
        is_single_comment = -1;
      }
    }
  }
}

int get_file_input(char s[], int limit)
{
  int c, i;
  i = 0;
  while ((c = getchar()) != EOF)
  {
    if (i > limit - 1)
    {
      printf("File Max lenght is: %d", limit);
      return -1;
    }
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return 0;
}
