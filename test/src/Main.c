#include "Main.h"

int main() {
	fputs("Put a number, get a factorial: ", stdout);

	uint64_t input_or_result = 0;
	scanf("%lu", &input_or_result);

	// This can be improved further by comparing against what cannot be computed on an amd64 processor.
	// That's `65`. ...and for `uint_32_t`, `12`!
	input_or_result = factorial(input_or_result);

	if (input_or_result == 0)
		puts("That would be impossible to calculate (I tried!).");
	else
		printf("That would be `%lu`!\n", input_or_result);
}

// Forget tail-recursive optimizations; we need to make sure we don't overflow!:
uint64_t factorial(uint64_t p_number) {
	if (p_number < 2)
		return p_number;

	// Recursive call:
	const uint64_t to_ret = p_number-- * factorial(p_number); // NOLINT(clang-diagnostic-unsequenced)

	if (to_ret < p_number)
		return 0;

	return to_ret;
}
