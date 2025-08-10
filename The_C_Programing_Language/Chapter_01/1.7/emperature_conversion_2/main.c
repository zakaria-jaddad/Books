#include <stdio.h>

/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */

#define STEP 20
#define UPPER 300

double fah_to_cels(int fahr);

int main(void)
{
  for (int i = 0; i < UPPER; i = i + STEP) {
    printf("%3d | %3.1f\n", i, fah_to_cels(i));
  }
}

double fah_to_cels(int fahr)
{
  return (5.0 / 9.0) * (fahr - 32.0);
}