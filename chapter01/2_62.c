#include <stdio.h>
#include <assert.h>

int int_shifts_are_arithmetic()
{
	int var = -1;

	var >>= ((sizeof(int) << 3) - 1);

	return -var;
}

int int_shifts_are_arithmetic_answer() /* the answer */
{
	int num = -1;
	return !(num ^ (num >> 1));
}

int main()
{
	printf("%d\n", int_shifts_are_arithmetic());

	assert(int_shifts_are_arithmetic_answer()); /* the answer */

	return 0;
}
