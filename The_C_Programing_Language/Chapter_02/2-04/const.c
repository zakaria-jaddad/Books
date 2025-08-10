#include <stdio.h>

void change_int(const int foo);

int main(void) 
{
	const int foo = 40;
	change_int(foo);
	return 0;
}

void change_int(const int foo) 
{
	bar = 50;
	printf("is this even working: %d\n", foo);
}
