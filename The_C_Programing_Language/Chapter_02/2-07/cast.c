#include <stdio.h>

int main(void) 
{
	const double foo = 9.5;
	
	// cast foo from double to int and store it in bar
	int bar = (int) foo;
	printf("This is the value of casted foo: %d\n", bar);
	return 0;
}
