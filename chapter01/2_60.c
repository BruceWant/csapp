#include <stdio.h>
/* for little endien */
unsigned lit_replace_byte (unsigned x, int i, unsigned char b)
{
	typedef char * byte_pointer;
	byte_pointer start = (byte_pointer) &x;
	start[i] = b;

	return x;
}

/* for big endien */
unsigned big_replace_byte (unsigned x, int i, unsigned char b)
{
	typedef char * byte_pointer;
	byte_pointer start = (byte_pointer) &x;
	start[3-i] = b;

	return x;
}

int is_little_end()
{
	int x = 1;
	typedef char * byte_pointer;

	byte_pointer start = (byte_pointer) &x;

	return start[0];
}

int main()
{
	unsigned x, y;

	if (is_little_end() == 1) {
		x = lit_replace_byte(0x12345678, 2, 0xAB);	
		y = lit_replace_byte(0x12345678, 0, 0xAb);
	} else {
		x = lit_replace_byte(0x12345678, 2, 0xAB);	
		y = lit_replace_byte(0x12345678, 0, 0xAb);
	}

	printf("%X\n", x);
	printf("%X\n", y);

	return 0;
}
