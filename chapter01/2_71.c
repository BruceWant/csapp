#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
	int size = sizeof (unsigned);

	int left_shift = (size - 1 - bytenum) << 3;
	int right_shift = (size - 1) << 3; 

	return (int) word << left_shift >> right_shift;
}

int main()
{
	packed_t word = 0x1df29e3b;

	printf("%x: %08x\n", 0x1df29e3b, xbyte(word, 3));
	printf("%x: %08x\n", 0x1df29e3b, xbyte(word, 2));
	printf("%x: %08x\n", 0x1df29e3b, xbyte(word, 1));
	printf("%x: %08x\n", 0x1df29e3b, xbyte(word, 0));

	return 0;
}
