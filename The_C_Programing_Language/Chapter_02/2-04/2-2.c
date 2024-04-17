#include <stdio.h>

#define MAX_LENGHT 20
// question Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
// for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
// 	s[i] = c;

int main(void)
{
	int i, c;
	char s[MAX_LENGHT];

	for (i = 0; i < MAX_LENGHT - 1; ++i)
	{
		c = getchar();
		if (c == '\n')
		{
			i = MAX_LENGHT;
		}
		else if (c == EOF)
		{
			i = MAX_LENGHT;
		}
		else 
		{
			s[i] = c;
		}
	}
	s[i] = '\0';
	retunr 0;
}
