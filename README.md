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

### Part 1: Standard Libc Functions

#### Character Classification & Conversion

These functions evaluate or convert single characters. They rely purely on logic and ASCII values.

`ft_isalpha`: `int ft_isalpha(int c);` <br />
Checks if the given character `c` is an alphabetic letter (A-Z or a-z). Returns 1 if true, 0 otherwise.

`ft_isdigit`: `int ft_isdigit(int c);` <br />
Checks if the given character `c` is a decimal digit (0-9). Returns 1 if true, 0 otherwise.

`ft_isalnum`: `int ft_isalnum(int c);` <br />
Checks if the given character `c` is alphanumeric (either a letter or a digit). Returns 1 if true, 0 otherwise.

`ft_isascii`: `int ft_isascii(int c);` <br />
Checks if the given character `c` fits into the standard ASCII character set (values 0 through 127). Returns 1 if true, 0 otherwise.

`ft_isprint`: `int ft_isprint(int c);` <br />
Checks if the given character `c` is a printable character, including the space character. Returns 1 if true, 0 otherwise.

`ft_toupper`: `int ft_toupper(int c);` <br />
If `c` is a lowercase letter, returns the corresponding uppercase letter. Otherwise, returns `c` unchanged.

`ft_tolower`: `int ft_tolower(int c);` <br />
If `c` is an uppercase letter, returns the corresponding lowercase letter. Otherwise, returns `c` unchanged.

#### Memory Manipulation

These functions operate on raw memory blocks byte by byte.

`ft_memset`: `void *ft_memset(void *b, int c, size_t len);` <br />
Fills the first `len` bytes of the memory area pointed to by `b` with the constant byte `c`. Returns a pointer to `b`. Include `<stddef.h>` for `size_t`.

`ft_bzero`: `void ft_bzero(void *s, size_t n);` <br />
Erases the data in the `n` bytes of memory starting at `s` by writing zeroes (`\0`). Include `<stddef.h>` for `size_t`.

`ft_memcpy`: `void *ft_memcpy(void *dst, const void *src, size_t n);` <br />
Copies `n` bytes from memory area `src` to `dst`. Memory areas must not overlap. Returns a pointer to `dst`. Include `<stddef.h>` for `size_t`.

`ft_memmove`: `void *ft_memmove(void *dst, const void *src, size_t len);` <br />
Copies `len` bytes from `src` to `dst`. It handles overlapping memory safely by copying in a non-destructive direction. Returns a pointer to `dst`. Include `<stddef.h>` for `size_t`.

`ft_memchr`: `void *ft_memchr(const void *s, int c, size_t n);` <br />
Scans the initial `n` bytes of memory `s` for the first instance of `c`. Returns a pointer to the matching byte or `NULL` if not found. Include `<stddef.h>` for `size_t`, `NULL`.

`ft_memcmp`: `int ft_memcmp(const void *s1, const void *s2, size_t n);` <br />
Compares the first `n` bytes of memory areas `s1` and `s2`. Returns an integer representing the difference between the first non-matching bytes. Include `<stddef.h>` for `size_t`.

#### String Inspection & Searching

These functions specifically operate on null-terminated C strings.

`ft_strlen`: `size_t ft_strlen(const char *s);` <br />
Calculates the length of the string `s`, excluding the terminating null byte. Include `<stddef.h>` for `size_t`.

`ft_strlcpy`: `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);` <br />
Safely copies `src` to `dst`, up to `dstsize - 1` characters, ensuring null-termination. Returns the length of `src`. Include `<stddef.h>` for `size_t`.

`ft_strlcat`: `size_t ft_strlcat(char *dst, const char *src, size_t dstsize);` <br />
Safely appends `src` to `dst`, ensuring null-termination. Appends at most `dstsize - strlen(dst) - 1` characters. Returns the initial length of `dst` plus the length of `src`. Include `<stddef.h>` for `size_t`.

`ft_strchr`: `char *ft_strchr(const char *s, int c);` <br />
Locates the first occurrence of `c` in string `s`. Returns a pointer to the character, or `NULL` if not found. Include `<stddef.h>` for `NULL`.

`ft_strrchr`: `char *ft_strrchr(const char *s, int c);` <br />
Locates the last occurrence of `c` in string `s`. Returns a pointer to the character, or `NULL` if not found. Include `<stddef.h>` for `NULL`.

`ft_strncmp`: `int ft_strncmp(const char *s1, const char *s2, size_t n);` <br />
Compares up to `n` characters of strings `s1` and `s2`. Returns the difference between the first non-matching characters. Include `<stddef.h>` for `size_t`.

`ft_strnstr`: `char *ft_strnstr(const char *haystack, const char *needle, size_t len);` <br />
Locates the first occurrence of the string `needle` within the string `haystack`, searching no more than `len` characters. Returns a pointer to the start of the found string, or `NULL`. Include `<stddef.h>` for `size_t`, `NULL`.

#### Allocations & Conversions

These functions involve converting string formats or dynamically allocating memory.

`ft_atoi`: `int ft_atoi(const char *str);` <br />
Converts a string representing a number into an `int`. Skips whitespace, handles one sign, and parses digits until a non-digit is hit.

`ft_calloc`: `void *ft_calloc(size_t count, size_t size);` <br />
Allocates contiguous memory for `count` elements of `size` bytes each. The allocated memory is initialized to zero bytes. Returns a pointer to the memory. Include `<stdlib.h>` for `malloc` and `<stddef.h>` for `size_t`.

`ft_strdup`: `char *ft_strdup(const char *s1);` <br />
Allocates enough memory to hold a copy of the string `s1`, copies the string into it, and returns a pointer to the new string. Include `<stdlib.h>` for `malloc`.

### Part 2: Additional Functions

These are custom string manipulation and file descriptor outputs that require memory allocation or specific system calls.

#### String Manipulation

`ft_substr`: `char *ft_substr(char const *s, unsigned int start, size_t len);` <br />
Allocates and returns a new substring from `s`, starting at index `start` and spanning a maximum of `len` characters. Include `<stdlib.h>` for `malloc` and `<stddef.h>` for `size_t`.

`ft_strjoin`: `char *ft_strjoin(char const *s1, char const *s2);` <br />
Allocates and returns a new string formed by concatenating `s1` and `s2`. Include `<stdlib.h>` for `malloc`.

`ft_strtrim`: `char *ft_strtrim(char const *s1, char const *set);` <br />
Allocates and returns a copy of `s1` with all characters present in `set` removed from both the absolute beginning and the absolute end of the string. Include `<stdlib.h>` for `malloc`.

`ft_split`: `char **ft_split(char const *s, char c);` <br />
Allocates and returns an array of strings (a double pointer), created by splitting the string `s` wherever the delimiter character `c` occurs. The array must be null-terminated. Include `<stdlib.h>` for `malloc` and `free`.

`ft_itoa`: `char *ft_itoa(int n);` <br />
Allocates and returns a string representing the integer `n`. Handles negative numbers and `0`. Include `<stdlib.h>` for `malloc`.

#### Iterators
`ft_strmapi`: `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` <br />
Applies function `f` to every character of string `s`. Allocates and returns a new string containing the modified characters. Include `<stdlib.h>` for `malloc`.

`ft_striteri`: `void ft_striteri(char *s, void (*f)(unsigned int, char*));` <br />
Applies function `f` to every character of string `s`. The characters are passed by address so the string is modified in-place.

#### File Descriptor (I/O) Functions

`ft_putchar_fd`: `void ft_putchar_fd(char c, int fd);` <br />
Writes the character `c` to the given file descriptor `fd`. Include `<unistd.h>` for `write`.

`ft_putstr_fd`: `void ft_putstr_fd(char *s, int fd);` <br />
Writes the string `s` to the given file descriptor `fd`. Include `<unistd.h>` for `write`.

`ft_putendl_fd`: `void ft_putendl_fd(char *s, int fd);` <br />
Writes the string `s` to the given file descriptor `fd`, followed by a newline `\n`. Include `<unistd.h>` for `write`.

`ft_putnbr_fd`: `void ft_putnbr_fd(int n, int fd);` <br />
Writes the integer `n` to the given file descriptor `fd` as characters. Include `<unistd.h>` for `write`.

### Part 3: Linked Lists

These functions require the `t_list` struct to be defined in the `libft.h` header.

`ft_lstnew`: `t_list *ft_lstnew(void *content);` <br />
Allocates and returns a new list node. Initializes `content` to the given argument and `next` to NULL. Include `<stdlib.h>` for `malloc`.

`ft_lstadd_front`: `void ft_lstadd_front(t_list **lst, t_list *new);` <br />
Adds the node `new` at the very beginning of the linked list `lst`.

`ft_lstsize`: `unsigned int ft_lstsize(t_list *lst);` <br />
Iterates through the list and returns the total count of nodes.

`ft_lstlast`: `t_list *ft_lstlast(t_list *lst);` <br />
Returns a pointer to the very last node of the list.

`ft_lstadd_back`: `void ft_lstadd_back(t_list **lst, t_list *new);` <br />
Adds the node `new` to the very end of the linked list `lst`.

`ft_lstdelone`: `void ft_lstdelone(t_list *lst, void (*del)(void *));` <br />
Frees the memory of the node's `content` using the provided `del` function, and then frees the node itself using `free`. Does not free the `next` node. Include `<stdlib.h>` for `free`.

`ft_lstclear`: `void ft_lstclear(t_list **lst, void (*del)(void *));` <br />
Deletes and frees the current node and all subsequent nodes in the list. Finally, sets the list pointer `lst` to `NULL`. Include `<stdlib.h>` for `free`.

`ft_lstiter`: `void ft_lstiter(t_list *lst, void (*f)(void *));` <br />
Iterates through the list and applies the function `f` to the `content` of each node.

`ft_lstmap`: `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` <br />
Iterates through the list, applies `f` to the `content` of each node, and builds a completely new list from the results. If an allocation fails, it uses `del` to clean up the new list.