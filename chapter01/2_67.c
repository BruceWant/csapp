#include <stdio.h>
#include <stdint.h> /* for int16_t */

/*
int bad_int_size_is_32() 
{
	int set_msb = 1 << 31;
	int beyond_msb = 1 << 32;

	return set_msb && !beyond_msb;
}
*/


int int_size_is_32()
{
	int set_msb = 1 << 31;
	int beyond_msb = set_msb << 1;

	return set_msb && !beyond_msb;
}

/* use int instead of int16_t for any machine,
 * here just for testing the function
 */
int16_t int_size_is_at_least_16()
{
	int16_t set_msb = 1 << 15;
		set_msb <<= 15;
		set_msb <<= 1;
	int16_t beyond_msb = set_msb << 1;

	return set_msb && !beyond_msb;
}
int main()
{
	int value =int_size_is_32(); /*  bad_int_size_is_32(); */
	int16_t value_16 = int_size_is_at_least_16();

	printf("%d\n", value);
	printf("%d\n", value_16);
	printf("%d\n", sizeof (int16_t));

	return 0;
}
