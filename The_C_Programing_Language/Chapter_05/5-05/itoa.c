#include <stdio.h>
#include <string.h>

#define MAXLENGTH 10000

void my_itoa(char *str, int number);
void reverse(char *str);

int main(void) {

  char number[MAXLENGTH];
  my_itoa(number, 1337);
  reverse(number);
  printf("The value should be 1337 = %s\n", number);

  my_itoa(number, -1337);
  // printf("this should be 7331- = %s\n", number);
  reverse(number);
  printf("The value should be -1337 = %s\n", number);
  return 0;
}

void my_itoa(char *str, int number) {

  int result = 0;

  int sign = (number < 0) ? -1 : 1;
  if (sign == -1)
    number *= -1;

  do {
    *str++ = (number % 10) + '0';
  } while (((int)(number /= 10)) > 0);

  if (sign == -1)
    *str++ = '-';
  *str = '\0';
}

void reverse(char *str) {

  int str_length = strlen(str);

  char placeholder[str_length + 1];
  strcpy(placeholder, str);

  for (int i = str_length - 1, j = 0; i >= 0 && placeholder[j] != '\0';
       i--, j++) {
    *(str + i) = placeholder[j];
  }
  *(str + str_length + 1) = '\0';
}
