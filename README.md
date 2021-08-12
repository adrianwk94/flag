# Flags

This library facilitates the use of flags in bit fields.

# How Flags work

Flags are used quite frequently in library APIs. It allows saving a multitude of configurations in a single variable.

This Stack Overflow link delves into its operation and utilities more deeply: [Bitwise-Shift operator in their enum definitions](https://stackoverflow.com/questions/3999922/why-use-the-bitwise-shift-operator-for-values-in-a-c-enum-definition)

## How to use the library?

The default in `flag_t` is a 32-bit unsigned integer, so you can store up to 32 flags. You can change the size of `flag_t` at any time in the header `flag.h`:

```c
typedef uint32_t flag_t; // default.
typedef uint64_t flag_t; // stores 64 flags.
typedef uint16_t flag_t; // stores 16 flags.
```

- **`FLAG(p)`** set `1` to` p` position:

```c++
enum {
	STATE_DEFAULT	= FLAG(0), // 00000000
	STATE_CHECKED	= FLAG(1), // 00000001
	STATE_FOCUSED	= FLAG(2), // 00000010
	STATE_FOCUS_KEY	= FLAG(3), // 00000100
	STATE_EDITED	= FLAG(4), // 00001000
	STATE_HOVERED	= FLAG(5), // 00010000
	STATE_PRESSED	= FLAG(6), // 00100000
	STATE_SCROLLED	= FLAG(7), // 01000000
	STATE_DISABLED	= FLAG(8), // 10000000
};
```

- **`flag_add`** add one or more flags to the bit field. It's like the `or` operator in C.

```c
flag_t test = STATE_FOCUSED | STATE_HOVERED; // 00010010
flag_add(&test, STATE_EDITED | STATE_PRESSED); // 0111010
```

- **`flag_remove`** removes one or more flags to the bit field.

```c
flag_remove(&test, STATE_HOVERED); // 0110010
```

- **`flag_reset`** removes all flags from the bit field.

```c
flag_reset(&test); // it's like: test = 0
```

- **`flag_parse`** converts a string with zeros and ones to a bit field.

```c
test = flag_parse("0111010");
```

- **`flag_string`** converts a bit field to a string. Ideal for display on the screen.

```c
printf("bits: %s\n", flag_string(test)); // out -> bits: 111010
```

- **`flag_check`** checks if a flag is active in the bit field. Use this function only with individual flags.
- **`flag_compare`** checks if one or more flags are active in the bit field.

## Compile Example

To compile in GCC, use the following commands within the library folder:

```
mkdir build
gcc -Isource/ -Wall main/main.c source/flag.c -o build/flag

In Windows: build\flag.exe
In Mac and Linux: ./build/flag
```

Tested with GCC, MinGW, XCode and Visual Studio 2017.

## Issue Report

You can report a problem in English or Spanish.

> Link to GitHub: <https://github.com/adrianwk94/flag>

## License

**Flag** is distributed with an MIT License. You can see LICENSE.txt for more info.
