#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_upper_meh(int c) { return (c >= 'A' && c <= 'Z'); }

int is_upper_dumb(int c)
{
  return (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", c) != NULL);
}
