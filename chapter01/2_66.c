#include <stdio.h>

int leftmost_one(unsigned x) /* wrong */
{
	unsigned tmp = x;
	
	tmp = x >> 1;
	x = (x | tmp) - tmp;

	tmp = x >> 2;
	x = (x | tmp) - tmp;

	tmp = x >> 4;
	x = (x | tmp) - tmp;

	tmp = x >> 8;
	x = (x | tmp) - tmp;

	tmp = x >> 16;
	x = (x | tmp) - tmp;

	return x;
}

int leftmost_one_answer(unsigned x)
{
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;

	return (x >> 1) + (x && 1);
}
int main()
{
	unsigned x = 0xff00,
			 y = 0x6600,
			 z = 0x40008000;

	printf("%x -> %x, %x -> %x, %x -> %x\n",
				x, leftmost_one(x),
				y, leftmost_one(y),
				z, leftmost_one(z));

	printf("%x -> %x, %x -> %x, %x -> %x\n",
				x, leftmost_one_answer(x),
				y, leftmost_one_answer(y),
				z, leftmost_one_answer(z));
	
	return 0;
}
