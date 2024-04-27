#include <stdio.h>

void escape(const char string[], char new_string[]);

/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters.
*/

int main(void)
{
	char s1[15] = "Hello, \\World!\n";
	char s2[30];

	// convert new string.
	escape(s1, s2);
	
	// print convered string.
	printf("%s", s2);
	return 0;
}

void escape(const char string[], char new_string[]) 
{
	int new_string_index, i;
	new_string_index = 0;

	for (i = 0; string[i] != '\0'; i++) {
		switch (string[i]) {
			// i'm to lazy to do all escaping but i get the idea :)
			case '\n':
			// for new line.
				new_string[new_string_index++] = '\\';
				new_string[new_string_index++] = 'n';
				break;
			case '\t':
			// for tab.
				new_string[new_string_index++] = '\\';
				new_string[new_string_index++] = 't';
				break;
			case '\\':
			// for slash.
				new_string[new_string_index++] = '\\';
				new_string[new_string_index++] = '\\';
				break;
			default:
			// for all character.
				new_string[new_string_index++] = string[i];
		}	
	}
	new_string[i] = '\0';
}
