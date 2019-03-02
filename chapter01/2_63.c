#include <stdio.h>
#include <assert.h>

unsigned srl(unsigned x, int k)
{
	/* Perform shift arigthmetically */
	unsigned xsra = (int) x >> k;

	xsra = xsra & (~(-1 << (8*sizeof(int) - k)));

	return xsra;
}

int sra(int x, int k)
{
	/* Perform shift logicallY */
	int xsrl = (unsigned) x >> k;

	xsrl = xsrl | (-1 << (8*sizeof(int) - k)); 

	return xsrl;
}


unsigned srl_answer(unsigned x, int k)
{
	unsigned xsra = (int) x >> k;

	int w = sizeof(int) << 3;
	int mask = (int) -1 << (w - k);
	return xsra & ~mask;
}

int sra_answer(int x, int k)
{
	int xsrl = (unsigned) x >> k;

	int w = sizeof(int) << 3;
	int mask = (int) - 1 << (w - k);

	int m = 1 << (w - 1);
	mask &= !(x & m) - 1;
	return xsrl | mask;
}

int main(int argc, char* argv[])
{
	unsigned test_unsigned = 0x12345678;
	int test_int = 0x12345678;
/*
	assert(srl(test_unsigned, 4) == test_unsigned >> 4);
	//assert(sra(test_int, 4) == test_int >> 4);

	printf("%08x\n", test_int >> 4);
	printf("%08x\n", sra(test_int, 4));
*/
	printf("%08x\n", srl_answer(test_unsigned));
	printf("%08x\n", sra_answer(test_int));
	test_unsigned = 0x87654321;
	test_int = 0x87654321;

	assert(srl(test_unsigned, 4) == test_unsigned >> 4);
	//assert(sra(test_int, 4) == test_int >> 4);

	return 0;
}
