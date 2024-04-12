#include <stdio.h>
#include <float.h>

int main(void)
{
	long int foo = 50; 
	unsigned int bar = 1;
	printf("Hello, World This is a value: %ld\n", foo);
	printf("This is an unsigned number: %u\n", bar);
	printf("This is the value of long double: %Lf\n", LDBL_MAX);
	return 0;
}
