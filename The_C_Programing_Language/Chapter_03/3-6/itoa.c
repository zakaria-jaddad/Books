#include <stdio.h>

#define EXIT_SUCCESS 0
void reverse(char string[], char new_string[]);
void itoa(long long n, char string[]);

int main(void) {
  long long number = -20000000000000000;
  char ascii_number[200];

  // convert intever to string ascii number
  itoa(number, ascii_number);

  // printing the converted number
  printf("This is the number: %lld = %s\n", number, ascii_number);
  // without reversing the string output of -200 should be 002-

  return EXIT_SUCCESS;
}

void itoa(long long n, char string[]) {
  char temp_string[200];
  int i;
  long long sign;

  // get sing from number
  // if number is less then 0, make it positive.
  if ((sign = n) < 0) {
    n = -n;
  }

  // why n is negative ??????
  unsigned long long current_number = n;
  i = 0;
  do {
    temp_string[i++] = current_number % 10 + '0';
  } while ((current_number = current_number / 10) > 0);

  // add sing if number is negative
  if (sign < 0) {
    temp_string[i++] = '-';
  }
  temp_string[i] = '\0';

  // all you need to do now is to reverse the string
  reverse(temp_string, string);
  return;
}

void reverse(char string[], char new_string[]) {
  /*
    i only thing of one algo is to count lenght of string
    and terevce it using that lenght.
  */

  // calculate string lenght.
  int lenght;
  for (lenght = 0; string[lenght] != '\0'; lenght++)
    ;

  int j = 0;
  for (int i = lenght - 1; i >= 0; i--, j++) {
    new_string[j] = string[i];
  }
  new_string[j] = '\0';
  return;
}
