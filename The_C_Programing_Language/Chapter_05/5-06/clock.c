#include <time.h>

int main(void) {
  clock_t begin = clock();

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  return 0;
}
