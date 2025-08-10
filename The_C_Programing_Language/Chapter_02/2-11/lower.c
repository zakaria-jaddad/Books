#include <stdio.h>

char lower(char letter);
int main(void)
{
	char my_upper = 'A';
	printf("%c\n", lower(my_upper));

	char foo = 'F';
	printf("%c\n", lower(foo));
}

// 
char lower(char letter) 
{
	return (letter >= 'A' && letter <= 'Z') ? letter + 32: letter;
}

