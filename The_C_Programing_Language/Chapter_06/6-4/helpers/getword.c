#include "../header.h"

static int pb_char = '\0';
static int pb_flag = 0;

int getch(void) { return (pb_flag == 1) ? pb_flag = 0, pb_char : getchar(); }

void ungetch(int c)
{
  pb_char = c;
  pb_flag = 1;
}

void ungets(const char s[])
{
  int i, c;
  i = 0;
  while ((c = s[i++]) != '\0')
  {
    ungetch(s[i++]);
  }
}

/* ft_getword: get next word or character from input */
int ft_getword(char *word, int lim)
{

  int c;
  char *w = word;

  while (isspace(c = getch()))
    ;
  if (c == EOF)
  {
    *w = EOF;
    return c;
  }
  if (!isprint(c))
  {
    *w = '\0';
    return c;
  }
  do
  {
    if (!isprint(c))
      break;
    lim--;
    *w++ = c;
    c = getch();
  } while (lim > 0);
  *w = '\0';
  return word[0];
}
