#include <stdio.h>
/*
  Formula: F = C * (9 / 5) + 32
 */
int main(void)
{

  // decaration
  float celsius, fahr;
  float lower, upper, step;

  // assignment
  lower = 0;
  upper = 300;
  step = 20;

  printf("Termpurature conversion program from Celsuis to Fah.\n");

  while (celsius <= upper)
  {
    fahr = (celsius + 32) * (9.0 / 5.0);
    printf("fahr: %3.0f | celsius: %6.1f\n", fahr, celsius);
    celsius = celsius + step;
  }
  printf("==========\n");

  
  for (int celsius = 300; celsius >= 0; celsius = celsius - 20)
  {
    printf("fahr: %3.0f | celsius: %6d\n", (celsius + 32) * (9.0 / 5.0), celsius);
  }
}