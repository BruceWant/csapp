#include <stdio.h>

typedef char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++) {
		printf("%.2x", start[i]);
	}
	printf("\n");
}

int main()
{
	int a = 1;
	byte_pointer start = (byte_pointer) &a;

	if (start[0] == 1)
		printf("Little endian\n");
	else 
		printf("Big endian\n");
	
	return 0;
}
