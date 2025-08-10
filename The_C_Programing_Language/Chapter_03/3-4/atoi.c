#include <stdio.h>
// NOTE: I LIKE THE FACE THAT I START USING NEOVIM AND I LIKE IT EVEN IF I'M SLOW AT IT, WRITTEN 18/4/2023
int my_atoi(const char s[]);

int main(void)
{
	int int_value = my_atoi(" -230");

	printf("%d\n", int_value);
	return 0;
}

int my_atoi(const char s[]) 
{
	int i, n, sign;

	// skip for white space.
	for (i = 0; s[i] == ' '; i++) 
		;

	// if current char is - set to -1 if not set to 1.
	sign = (s[i] == '-') ? -1 : 1;

	// check for sign 
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
	}

	for (n = 0; s[i] >= '0' && s[i] <= '9'; i++)
	{
		n = n * 10 + (s[i] - '0');
	}
	return sign * n;
}
