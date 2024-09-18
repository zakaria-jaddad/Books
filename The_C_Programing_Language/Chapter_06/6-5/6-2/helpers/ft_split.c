#include "../includes/header.h"

char **ft_split(char *string, char *charset)
{
  int i;
  int words_count = count_words(string, charset);
  char **head = (char **)malloc((sizeof(char *) * words_count) + 1);
  if (head == NULL)
    return NULL;

  for (i = 0; i < words_count; i++)
  {
    char *word = get_current_word(string, charset, (i + 1));
    int word_length = ft_strlen(word, charset);
    head[i] = (char *)malloc((sizeof(char) * word_length) + 1);
    head[i] = ft_strncpy(head[i], word, word_length);
  }
  head[i] = NULL;
  return head;
}
