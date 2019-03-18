#include <stdio.h>

unsigned rotate_left(unsigned x, int n)
{
	unsigned mask = 0,
			 head = 0,
			 tail = 0;

	mask = (~mask) << (31 - n) << 1; /* shift left (32 - n) bits */
	head = mask & x;
	tail = head >> (31 - n) >> 1;
	x = (x << n) | tail;

	return x;
}

int main()
{
	unsigned x = 0x12345678;

	printf("  x:  %x\n", x);
	printf("n=4:  %x\n", rotate_left(x, 4));
	printf("n=20: %x\n", rotate_left(x, 20));
	printf("n=0:  %x\n", rotate_left(x, 0));

	return 0;
}
