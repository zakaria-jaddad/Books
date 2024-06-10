/* representation of number of days each month has for leap and non leap year */
#include <stdio.h>
static char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 31, 31, 30, 31, 30, 31},
                             {0, 31, 29, 31, 30, 31, 31, 31, 30, 31, 30, 31}};

/* month day: set month, day, from day of the year */
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void) {
  int y = 1984, m = 6, d = 30, yd = 366;
  int *pm, *pd;

  month_day(y, yd, pm, pd);
  printf("Month: %d, Day: %d\n", *pm, *pd);
  return 0;
}

/* month day: set month, day, from day of the year */
void month_day(int year, int yearday, int *pmonth, int *pday) {

  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 ||
         year % 400 == 0; /* leap is either 0 or 1 */

  if (leap) {
    if (yearday > 365) {
      printf("error: not a valid day\n");
      return;
    }
  } else {
    if (yearday > 366) {
      printf("error: not a valid day\n");
      return;
    }
  }

  for (i = 1; yearday > daytab[leap][i];
       i++) { /* this checks if there is more days than a month */
    yearday -= daytab[leap][i];
  }
  *pmonth = i;
  *pday = yearday;
}
