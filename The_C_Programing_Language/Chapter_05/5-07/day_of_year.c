#include <stdio.h>

/* representation of number of days each month has for leap and non leap year */
static char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 31, 31, 30, 31, 30, 31},
                             {0, 31, 29, 31, 30, 31, 31, 31, 30, 31, 30, 31}};

/* day of year: set day of the year from month and day */
int day_of_year(int year, int month, int day);

int main(void) {
  int y = 1984, m = 6, d = 30, yd = 366;
  int *pm, *pd;

  printf("Day: %d\n", day_of_year(y, m, d));
  return 0;
}

/* day of year: set day of the year from month and day */
int day_of_year(int year, int month, int day) {

  int i, leap;
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  if (month < 1 && month > 12) {
    printf("error: invalid month\n");
    return -1;
  }
  if (day < 0 || day > daytab[leap][month]) {
    printf("error: invalid day\n");
    return -1;
  }

  for (i = 1; i < month; i++) {
    day += daytab[leap][i];
  }
  return day;
}
