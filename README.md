# FT_PRINTF

My 2nd project at 42 Network's Hive Helsinki 🐝

A printing function with a template and value conversions!

> [!TIP]
> If you're at a 42 school and doing this project: It's genuinely so much better to ask fellow students instead of reading online solutions ✨

---

## Description

This project's about creating a simplified reimplimentation of the `stdio` C library's `printf` function, and introducing us to making variadic functions in C.

The `printf` function accepts a string as the first argument, in which percentage signs indicate slots in which to print values of the corresponding type which are provided as variadic arguments.

This `ft_printf` can convert and print the following types:
- `%c`: Single character
- `%s`: Array/pointer of character(s)
- `%p`: Pointer's memory address, in hexadecimal notation
- `%i`: Integers (within C's limits for `int` values), base 10
- `%d`: Same as `%i`
- `%u`: Unsigned integers (i.e. no negative integers but higher maximum value)
- `%x`: Hexadecimal (base 16) integers, with lowercase a-f 
- `%X`: Hexadecimal (base 16) integers, with uppercase A-F
- `%%`: A percentage sign 

This `ft_printf` handles `write` errors and returns values like the original `printf` does, except in cases where the original `printf` throws compile warnings: Since we're required to compile all projects with `-Wall -Wextra -Werror`, those cases failing to compile means they're out of scope for `ft_printf`.

(This project includes [libft](https://github.com/EvAvKein/libft), as allowed in the assignment instructions)

---

## Usage

> [!NOTE]
> Code was written and tested for Linux (using Hive's Ubuntu iMacs)

> Testing was done using `main.test.c` (and variants thereof) and [printfTester](https://github.com/Tripouille/printfTester)

- `#include "[path to ft_printf.h]"` in your program's header file or relevant C files
- Compile by running `make`
- Compile your own program with the `libftprintf.a` file created in the previous step

---

## [Credits]

- [Eve Keinan](https://github.com/EvAvKein)
