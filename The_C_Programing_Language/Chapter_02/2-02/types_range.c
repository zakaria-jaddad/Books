#include <stdio.h>
#include <limits.h>
#include <float.h>

/* 
  Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
  variables, both signed and unsigned, by printing appropriate values from standard headers
  and by direct computation. Harder if you compute them: determine the ranges of the various
  floating-point types.
*/

int main(void)
{
  // chars
  printf("max value of signed char:          %30d\n", SCHAR_MAX);
  printf("min value of signed char:          %30d\n", SCHAR_MIN);
     
  printf("min value of unsigned char:        %30d\n", 0);
  printf("max value of unsigned char:        %30d\n", UCHAR_MAX);
     
  printf("min value of char:                 %30d\n", CHAR_MIN);
  printf("max value of char:                 %30d\n", CHAR_MAX);
     
  // shorts     
  printf("min value of signed shorts:        %30d\n", SHRT_MIN);
  printf("max value of signed shorts:        %30d\n", SHRT_MAX);
     
  printf("min value of unsigned shorts:      %30d\n", 0);
  printf("max value of unsigned shorts:      %30d\n", USHRT_MAX);
     
  printf("min value of shorts:               %30d\n", SHRT_MIN);
  printf("max value of shorts:               %30d\n", SHRT_MAX);
     
  // ints     
  printf("min value of unsigned ints:        %30d\n", 0);
  printf("max value of unsigned ints:        %30d\n", UINT_MAX);
     
  printf("min value of signed ints:          %30d\n", INT_MIN);
  printf("max value of signed ints:          %30d\n", INT_MAX);
     
  // longs     
  printf("min value of unsigned longs:       %30d\n", 0);
  printf("max value of unsigned longs:       %30ld\n", ULONG_MAX);
     
  printf("min value of signed longs:         %30ld\n", LONG_MIN);
  printf("max value of signed longs:         %30ld\n", LONG_MAX);

  // long longs 
  printf("min value of unsigned long longs:  %30d\n", 0);
  printf("max value of unsigned long longs:  %30lld\n", ULLONG_MAX);

  printf("min value of signed long longs:    %30lld\n", LLONG_MIN);
  printf("max value of signed long longs:    %30lld\n", LLONG_MAX);
  return 0;
}