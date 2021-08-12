/*
Bit-field Flags. Version 0.1.0

Original code by Adrian Guerrero Vera (adrianwk94@gmail.com)
MIT License
Copyright (c) 2021 Adrian Guerrero Vera

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "flag.h"

#define MAX_CAPACITY (sizeof(flag_t)*8)

void flag_add(flag_t* bit_field, flag_t bits) {
	(*bit_field) = (*bit_field) | bits;
}

void flag_remove(flag_t* bit_field, flag_t bits) {
	(*bit_field) = (*bit_field) ^ ((*bit_field) & bits);
}

void flag_reset(flag_t* bit_field) {
	(*bit_field) = 0;
}

flag_t flag_parse(const char* bit_field_string) {
	flag_t	result = 0;
	uint8_t position = 0;
	char	bit = bit_field_string[0];

	while (position < MAX_CAPACITY && bit != '\0') {
		result = (result << 1) | (bit == '1' ? 1 : 0);
		position++;
		bit = bit_field_string[position];
	}
	return result;
}

const char* flag_string(flag_t bit_field) {
	static char result[MAX_CAPACITY+8];

	uint8_t position = 0;
	uint8_t size = 0;
	flag_t 	pattern = 0;

	for (flag_t i = bit_field; i; i = i >> 1) {
		size++;
	}

	pattern = FLAG(size);

	while (position < size) {
		result[position] = flag_check(bit_field, pattern) ? '1' : '0';

		position++;
		bit_field = bit_field << 1;
	}
	result[position] = '\0';
	return result;
}

bool flag_check(flag_t bit_field, flag_t bit) {
	return bit_field & bit ? true : false;
}

bool flag_compare(flag_t bit_field, flag_t bits) {
	return (bit_field & bits) == bits;
}

#undef MAX_CAPACITY
