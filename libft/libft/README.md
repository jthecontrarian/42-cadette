*This project has been created as part of the 42 curriculum by jelau.*

# Libft

## Description

Libft is a library for 42 Cadette Milestone 1 written in C. The goal is to write common functions built into common libraries in C. This library contains function that manipulate characters, strings, memory, output, and linked lists.

## Instructions

### Compilation

Clone the repository, then run `make` to run the Makefile at its root to create `libft.a`, the library.

```sh
git clone <repository_url> libft
cd libft
make
```

After making the library `libft.a`, you can run `make clean` to remove the generated object files, `make fclean` to remove both the object files and the library. Alternatively, you may run `make re` to do a full clean and rebuild.

### Usage

Drop the generated `libft.a` file into your working directory, then you can include it in your program. 

Suppose we have a main.c` file containing our example:

```c
#include "libft.h"

int	main(void)
{
	char	*joined;

	joined = ft_strjoin("Hello ", "world!");
	ft_putendl_fd(joined, 1);
	free(joined);
	return (0);
}
```

We can then compile our `main.c` and link it against the library (run from the repository root):

```sh
cc -Wall -Wextra -Werror main.c libft.a -o program.out
./program.out
```

If all is done correctly, you should get the output `Hello world!' in your terminal.

## Library Description

### Character functions

| Function | Description |
|---|---|
| `ft_isalpha` | Checks for an alphabetic character |
| `ft_isdigit` | Checks for a decimal digit |
| `ft_isalnum` | Checks for a letter or digit |
| `ft_isascii` | Checks for an ASCII value |
| `ft_isprint` | Checks for a printable character, including space |
| `ft_toupper` | Converts a lowercase letter to uppercase |
| `ft_tolower` | Converts an uppercase letter to lowercase |

### String functions

| Function | Description |
|---|---|
| `ft_strlen` | Returns the length of a string |
| `ft_strlcpy` | Copies a string into a buffer of a given size |
| `ft_strlcat` | Appends a string to a buffer of a given size |
| `ft_strchr` | Finds the first occurrence of a character |
| `ft_strrchr` | Finds the last occurrence of a character |
| `ft_strncmp` | Compares up to n characters of two strings |
| `ft_strnstr` | Finds a substring within the first len characters |
| `ft_atoi` | Converts a string to an int |
| `ft_striteri` | Applies a function to each character of a string, in place |

### Memory functions

| Function | Description |
|---|---|
| `ft_memset` | Fills memory with a byte value |
| `ft_bzero` | Fills memory with zeros |
| `ft_memcpy` | Copies memory between non-overlapping areas |
| `ft_memmove` | Copies memory safely when areas may overlap |
| `ft_memchr` | Finds a byte in a memory area |
| `ft_memcmp` | Compares two memory areas |

### Functions that allocate memory to heap

| Function | Description |
|---|---|
| `ft_calloc` | Allocates zero-initialized memory for an array |
| `ft_strdup` | Duplicates a string |
| `ft_substr` | Extracts a substring from a string |
| `ft_strjoin` | Join two strings into a new one |
| `ft_strtrim` | Removes the characters in a set from both ends of a string |
| `ft_split` | Splits a string by a delimiter into a NULL-terminated array |
| `ft_itoa` | Converts an int to a string |
| `ft_strmapi` | Builds a new string by applying a function to each character |

### Output

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd` | Writes a string to a file descriptor |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor |
| `ft_putnbr_fd` | Writes an integer to a file descriptor |

### Linked lists

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node |
| `ft_lstadd_front` | Adds a node at the beginning of a list |
| `ft_lstsize` | Counts the nodes in a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstadd_back` | Adds a node at the end of a list |
| `ft_lstdelone` | Deletes and free one node of a list|
| `ft_lstclear` | Deletes and free a node and all its successors |
| `ft_lstiter` | Applies a function to the content of each node |
| `ft_lstmap` | Creates a new list and apply a function to each node's content |

## Resources

- Ubuntu Linux manual
- [Makefile Tutorial](https://makefiletutorial.com/)