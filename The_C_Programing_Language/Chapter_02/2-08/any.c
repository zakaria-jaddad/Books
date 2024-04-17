#include <stdio.h>

int any(const char s1[], const char s2[]);

int main(void)
{
	char baz[4] = "helb";
	char bar[3] = "hel";

	int foo = squeeze(baz, bar);	
	printf("%d\n", foo);
	return 0;
}

int any(const char s1[], const char s2[]) 
{
	for (int i = 0; s1[i] != '\0'; i++)
	{
		for (int j = 0; s2[j] != '\0'; j++)
		{
			if (s1[i] == s2[j])
			{
				return i;
			}

		}

	}
	return -1;
}
