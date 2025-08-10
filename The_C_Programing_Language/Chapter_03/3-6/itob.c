#include <stdio.h>
void itob(long long number, char string[], int base);
/*
  Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into
  a base b character representation in the string s. In particular, itob(n,s,16)
  formats s as a hexadecimal integer in s.
*/
void reverse(char temp_string[], char new_string[]);

int main(void) {

  long long number = 157;

  char string_number[200];
  int base = 8;

  // convert number to it's base
  itob(number, string_number, base);
  printf("number is: %lld = %s\n", number, string_number);
  return 0;
}

/*
  I'm going to use just the bases in the man helper
  we have:
    - octal
    - hex

  I'm not gonna do the binary case i just don't
*/
void itob(long long number, char string[], int base) {
  char temp_string[200];

  // check if number is negative.
  long long sign;
  if ((sign = number) < 0) {
    number *= -1;
  }
  unsigned long long current_number = number;

  int i = 0;
  do {
    temp_string[i++] = current_number % base + '0';

  } while ((current_number = (unsigned long long)current_number / base) > 0);

  // add hex prefixer
  if (base == 16) {
    temp_string[i++] = 'x';
    temp_string[i++] = '0';
  } else if (base == 8) {
    temp_string[i++] = 'o';
    temp_string[i++] = '0';
  }
  temp_string[i] = '\0';
  reverse(temp_string, string);

  return;
}

void reverse(char temp_string[], char new_string[]) {
  // calculate string lenght.
  int lenght;
  for (lenght = 0; temp_string[lenght] != '\0'; lenght++)
    ;
  // declare a temp array

  int j = 0;
  for (int i = lenght - 1; i >= 0; i--, j++) {
    new_string[j] = temp_string[i];
  }
  new_string[j] = '\0';
  return;
}
