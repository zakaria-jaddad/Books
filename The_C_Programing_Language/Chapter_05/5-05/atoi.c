#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

int my_atoi(const char *str);

int main(void) {
  // int number = my_atoi("hello world++-1337");
  int number = my_atoi("---00300hello");
  printf("%d\n", number);
  return 0;
}

int my_atoi(const char *str) {

  int result = 0;
  int sign = 1;

  while (!isdigit(*str)) {
    if (*str == '-' || *str == '+') {
      sign *= (*str == '-') ? -1 : 1;
    }
    str++;
  }

  while (isdigit(*str)) {
    result = result * 10 + (*str++ - '0');
  }

  return sign * result;
}
