#include <stdio.h>

enum TRAFIC_LIGHT {RED = 0, YELLOW = 1, GREEN = 2}; 

int main(void)
{
	int current_light = 0;

	// switch 
	switch (current_light) {
		case RED : 
			printf("current light is red\n");
			break;
		case GREEN : 
			printf("current light is green\n");
			break;
		default : 
			printf("current light is red\n");
	}
	return 0;
}
