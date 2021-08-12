#include "flag.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

// https://stackoverflow.com/questions/3999922/why-use-the-bitwise-shift-operator-for-values-in-a-c-enum-definition

enum {
	STATE_DEFAULT	= FLAG(0),
	STATE_CHECKED	= FLAG(1),
	STATE_FOCUSED	= FLAG(2),
	STATE_FOCUS_KEY	= FLAG(3),
	STATE_EDITED	= FLAG(4),
	STATE_HOVERED	= FLAG(5),
	STATE_PRESSED	= FLAG(6),
	STATE_SCROLLED	= FLAG(7),
	STATE_DISABLED	= FLAG(8),
};

int main() {

	flag_t test = STATE_FOCUSED | STATE_HOVERED;
	assert(flag_check(test, STATE_FOCUSED));

	flag_add(&test, STATE_EDITED | STATE_PRESSED);
	assert(flag_check(test, STATE_PRESSED));
	assert(flag_compare(test, flag_parse("0111010")));

	flag_remove(&test, STATE_HOVERED);
	assert(flag_check(test, STATE_HOVERED) == false);


	const char* bit_string = flag_string(test);

	printf("bits: %s\n", bit_string);
	
	return 0;
}

