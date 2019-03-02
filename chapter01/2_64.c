#include <stdio.h>
#include <assert.h>

int any_odd_one(unsigned x)
{
	return !!(0xAAAAAAAA & x);
}

int main(int argc, char* argv[])
{
	printf("0x2: %d\n", any_odd_one(0x2));
	printf("0x4: %d\n", any_odd_one(0x4));

	assert(any_odd_one(0x2));  /* effect equal to first printf() */
	assert(!any_odd_one(0x4)); /* effect equal to second printf() */
	
/*	printf("0xAAAAAAAA & 0x2: %d\n", 0xAAAAAAAA & 0x2);
*	printf("0xAAAAAAAA & 0x4: %d\n", 0xAAAAAAAA & 0x4);
*	
*/
	return 0;
}
