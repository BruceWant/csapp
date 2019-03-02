#include <stdio.h>

int main()
{
	int x, y, z;

	x = 0x89ABCDEF;
	y = 0x76543210;

	z = (x & 0xff) | (y & (~0xff));
	printf("%.2X", z);

	return 0;
}
