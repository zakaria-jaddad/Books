#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int my_atoi(const char s[]);

int main(void)
{

	const char foo[7] = "1234567";
	printf("This is the value of my atoi: %d\n", my_atoi(foo));
	return 0;
}

// this is just a basic function i don't consider negative values here it's from the book.
int my_atoi(const char s[])
{
	int i, r;
	i = r = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			r = (r * 10) + s[i] - '0';
		}
		++i;
	}
	return r;
}
