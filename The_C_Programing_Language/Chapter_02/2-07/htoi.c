#include <stdio.h>
#include <ctype.h>

int htoi(const char s[]);

int main(void)
{
	printf("value of htoi: %d\n", htoi("-0x1F"));
	printf("value of htoi: %d\n", htoi("0x1F"));
	return 0;
}

int htoi(const char s[]) 
{
	int signe;
	signe = 1;

	int string_length;
	string_length = 0;

	int i, r;
	i = r = 0;

	// get length of given string 
	while(s[string_length] != '\0')
		++string_length;

	// if negative number 
	if (s[0] == '-') 
	{

		if (string_length < 4 || (s[1] != '0' && tolower(s[2]) != 'x'))
		{
			return -1;
		}
		else
		{
			signe = -1;
		}
	}
	
	// if string is less then 3 or doesn't have 0x or 0X in it.
	else if (string_length < 3 || (s[0] != '0' && tolower(s[1]) != 'x'))
	{
		return -1;
	}

	// current string is a hex number.
	for (i = 0; s[i] != '\0'; ++i)
	{
		// checking for number 
		if (s[i] >= '0' && s[i] <= '9')
		{
			r = (r * 16) + s[i] - '0';
		}
		// checking for a digit to lower wouldn't efeect a number character 1 would be 1 by A wouldb be a.
		char lower_character = tolower(s[i]); 

		if (lower_character >= 'a' && lower_character <= 'f') 
		{
			// add 10 becuase a has a value of 10 in hex
			r = (r * 16) + (lower_character - 'a') + 10;

		}

	}

	return signe * r;
}
