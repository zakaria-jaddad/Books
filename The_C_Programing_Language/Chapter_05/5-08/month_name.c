#include <stdio.h>

/* month_name: return name of n-th month */
char *month_name(int n);

int main(void) {
  char *myMonth = month_name(10);
  printf("My Month: %s\n", myMonth);
  return 0;
}

char *month_name(int n) {
  static char *name[] = {
      "Illegal month", "January", "Faburary", "Mars",    "April",    "May",
      "Jun",           "July",    "August",   "Octobre", "Novomber", "December",
  };

  return (n < 1 || n > 12) ? name[0] : name[n];
}
