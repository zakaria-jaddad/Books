#include  <stdio.h>

int binsearch(const int x, const int v[], int n);

int main(void)
{
	int x = 0;
	int bar[7] = {1, 2, 3, 4, 5, 6, 7};
	int n = 7;

	int result;

	result = binsearch(x, bar, n);
	printf("value is: %d\n", result); // value is -1
	return 0;
}

int binsearch(const int x, const int v[], int n) 
{
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low < high) {
		mid = (low + high) / 2;
		if (x <= v[mid]) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}

	return (v[mid] == x) ? mid : -1;
}
