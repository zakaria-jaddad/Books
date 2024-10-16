#include "header.h"

int main(int argc, char **argv)
{
  char *hello;

  hello = (char *) my_calloc(7, sizeof(char));
  hello = "hello";
  printf("allocated string is  = %s\n", hello);
  return (EXIT_SUCCESS);
}

void *my_calloc(size_t count, size_t size)
{
  char *ptr;

  ptr = (char *) my_malloc(size * count);
  if (ptr == NULL)
    return NULL;
  for (int i = 0; i < count; ++i)
    *(ptr + i) = 0;
  return (void *) ptr;
}
