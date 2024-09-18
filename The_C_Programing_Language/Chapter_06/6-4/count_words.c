#include "header.h"
#include <stdio.h>

struct key keytab[] = {{"auto", 0},     {"break", 0},    {"case", 0},
                       {"char", 0},     {"const", 0},    {"continue", 0},
                       {"default", 0},  {"unsigned", 0}, {"void", 0},
                       {"volatile", 0}, {"while", 0},    {NULL, 0}};

#define NKEYS (sizeof(keytab) / sizeof(struct key))

int main(int argc, char *argv[])
{
  struct key *p;
  char word[MAXWORD];

  while (ft_getword(word, MAXWORD) != EOF)
  {
    if (isprint(word[0]))
    {
      printf("word : %s\n", word);
      if ((p = binsearch(word, keytab, NKEYS)) != NULL)
        p->count++;
    }
  }

  /* Print word and it's counter */
  for (p = keytab; p->word != NULL; p++)
  {
    if (p->count > 0)
      printf("\n%4d %s\n", p->count, p->word);
  }
  return 0;
}
