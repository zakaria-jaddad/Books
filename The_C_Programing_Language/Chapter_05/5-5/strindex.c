#include <stdio.h>

int my_strindex(char *str1, const char *str2);

int main(void) {

  int index = my_strindex("do Hello, World\n", "Hello, ");
  printf("should be 4: %d\n", index);

  int anotherIndex = my_strindex("h", "h");
  printf("should be 1: %d\n", anotherIndex);

  int anotherAnotherIndex = my_strindex("dd", "hello");
  printf("should be -1: %d\n", anotherAnotherIndex);
  return 0;
}

/*
   strindex return's the first index of str1 if n chars equals -1 is they are
   not what is my algo
*/
int my_strindex(char *str1, const char *str2) {

  int i = 0;
  while (*str1 != '\0') {
    i++;
    int counter = 1;
    while (*str1++ == *str2++ && *str1 != '\0') {
      if (*str2 == '\0')
        return i;
      counter++;
    }
    str2 = str2 - counter;
  }
  return -1;
}
