#include <stdio.h>

int lower_one_mask(int n)
{
	int x = 0xffffffff;

	x = x << n - 1 << 1;

	return ~x; 
}


int main()
{
	int n = 1;

	scanf("%d", &n);

	printf("%x\n", lower_one_mask(n));

	return 0;
}
