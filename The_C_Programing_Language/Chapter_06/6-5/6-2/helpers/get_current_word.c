#include "../includes/header.h"
#include <string.h>

#define MULTILINE_COMMENT_START "/*"
#define MULTILINE_COMMENT_END "*/"
#define SINGLE_COMMENT "//"
#define COMMENT_TRIGGER_LENGTH 2

static int is_multiline_comment_start(char *str)
{
  if (strncmp(MULTILINE_COMMENT_START, str, COMMENT_TRIGGER_LENGTH) == 0)
    return 1;
  return 0;
}

static int is_multiline_comment_end(char *str)
{
  if (strncmp(MULTILINE_COMMENT_END, str, COMMENT_TRIGGER_LENGTH) == 0)
    return 1;
  return 0;
}

static int is_single_comment_start(char *str)
{
  if (strncmp(SINGLE_COMMENT, str, COMMENT_TRIGGER_LENGTH) == 0)
    return 1;
  return 0;
}

static int is_single_comment_end(char *str)
{
  if (strncmp("\n", str, 1) == 0)
    return 1;
  return 0;
}

char *get_current_word(char *str, char *charset, int index)
{
  int multiline_comment_flag = 0;
  int single_comment_flag = 0;
  int count = 0;
  int i = 0;

  while (str[i])
  {
    if (is_multiline_comment_start(&str[i]) && multiline_comment_flag == 0)
      multiline_comment_flag = 1;
    else if (is_multiline_comment_end(&str[i]) && multiline_comment_flag)
      multiline_comment_flag = 0;

    if (is_single_comment_start(&str[i]) && single_comment_flag == 0)
      single_comment_flag = 1;
    else if (is_single_comment_end(&str[i]) && single_comment_flag)
      single_comment_flag = 0;

    if (!multiline_comment_flag && !single_comment_flag)
    {
      if (!ft_strchr(charset, str[i]) &&
          (i == 0 || ft_strchr(charset, str[i - 1])))
      {
        count++;
        if (count == index)
        {
          return &str[i];
        }
      }
    }
    i++;
  }
  return str;
}
