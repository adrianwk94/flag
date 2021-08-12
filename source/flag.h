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

#ifndef FLAG_H
#define FLAG_H

#include <stdint.h>
#include <stdbool.h>

// Caution: the maximum for P is flag_t (default: 32)
#define FLAG(p) ((p > 0) ? (1 << ((p) - 1)) : (0))

typedef uint32_t flag_t; // you can change the type of uint, but you must recompile the flag.c

void 		flag_add	(flag_t* bit_field, flag_t bits); // add one or more bits to the variable.
void		flag_remove	(flag_t* bit_field, flag_t bits); // remove one or more bits from the variable.
void		flag_reset	(flag_t* bit_field); // sets the variable to zero.

flag_t		flag_parse	(const char* bit_field_string);
const char* flag_string	(flag_t bit_field);

bool		flag_check	(flag_t bit_field, flag_t bit); // check if bit is in bit_field.
bool		flag_compare(flag_t bit_field, flag_t bits); // checks if one or more bits is in the bit_field.

#endif
