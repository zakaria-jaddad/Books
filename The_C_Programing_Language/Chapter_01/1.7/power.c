#include <stdio.h>

int power(int m, int n);

int main(void)
{

  int i;
  for (i = 0; i < 10; ++i)
  {
    printf("%d %d %d\n", i, power(2, i), power(-3, i));
  }
  return 0;
}

int power(base, n)
int base, n;
{
  int p;
  p = 1;
  for (int i = 1; i <= n; ++i)
  {
    p = p * base;
  }
  return p;
}