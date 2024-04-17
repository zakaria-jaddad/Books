#include <stdio.h>

enum Days {Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thu = 5, Fri = 6, Sat = 7};

int main(void) 
{
	// today
	enum Days today = Sun;

	if (today == Sun || today == Sat)
	{
		printf("Yay it's Weekend\n");
	}
	else 
	{
		printf("Time for some work\n");
	}
	return 0;
}
