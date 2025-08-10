#include <stdio.h>

char * squeeze(char s1[], const char s2[]);

int main(void)
{
	char baz[4] = "helb";
	char bar[3] = "hel";

	char *foo = squeeze(baz, bar);	
	printf("%c\n", foo[0]);
	return 0;
}

char * squeeze(char s1[], const char s2[]) 
{
	int lenght = 0;
	for (int i = 0; s1[i] != '\0'; i++)
		lenght++;
	
	// new array 
	char new_string[lenght + 1];
	
	int i, new_string_index;
	i = new_string_index = 0;

	while(s1[i] != '\0')
	{
		int is_letter_found = -1;
		for (int j = 0; s2[j] != '\0'; j++) 
		{
			if (s1[i] == s2[j]) 
			{
				is_letter_found = 0;
				break;
			}

		}
		if (is_letter_found == -1)
		{
			// assigne not found letter in new-string and increment it't index
			new_string[new_string_index++] = s1[i];
		}

		i++;
	}
	new_string[new_string_index] = '\0';
	return new_string; 

}
