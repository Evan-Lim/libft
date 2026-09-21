*This project has been created as part of the 42 curriculum by elim-hon.*

# Libft

## Description

Libft is a custom C library that reimplements a set of standard libc functions and adds additional utility functions for string manipulation, memory handling, output, and linked lists.
The goal of this project is to build a solid foundation in C programming, understand how common library functions work under the hood, and create a reusable library that will be used in later 42 projects.

The library is compiled into `libft.a` and must be placed at the root of the repository. All functions follow the 42 Norm and are written without global variables. Helper functions are declared `static` to restrict their scope.

## Instructions

### Compilation

```sh
make
```

This creates libft.a at the root of the repository.

### Cleaning

```sh
make clean	# remove object files
make fclean	# remove object files and libft.a
make re		# recompile everything
```

### Usage

Include the header in your source file:

```c
#include "libft.h"
```
Compile your program with the library:

```c
cc -Wall -Wextra -Werror your_file.c libft.a -o your_program
```

The library is compiled with `cc -Wall -Wextra -Werror` and uses `ar` to create the archive. No external functions are used except those explicitly allowed in the subject (`malloc`, `free`, `write`).

## Resources

- `man` pages for libc functions: `strlen(3)`, `memcpy(3)`, `strlcpy(3)`, `calloc(3)`, etc.
- 42 Norm documentation
- C99 standard (without using the `restrict` qualifier or `-std=c99`)
- BSD libc documentation for `strlcpy`, `strlcat` and `bzero`
- Peer learning and campus discussions

### AI Usage

AI was used to help structure this README and to re

## Library Description

### Character Conversion and Description Functions

`ft_isalpha`: `int ft_isalpha(int c);` <br />
Checks if the given character `c` is an alphabetic letter (A-Z or a-z). Returns 1 if true, 0 otherwise.

`ft_isdigit`: `int ft_isdigit(int c);` <br />
Checks if the given character `c` is a decimal digit (0-9). Returns 1 if true, 0 otherwise.

`ft_isalnum`: `int ft_isalnum(int c);` <br />
Checks

