*This project has been created as part of the 42 curriculum by akacpere.*

---
## Description
**Libft** is a first project in the 42 curriculum. The goal of this project is to create a custom C library (`libft.a`) by replicating a collection of standard C library (libc) functions, along with additional functions for string, memory, and linked list manipulation.

By implementing these functions from scratch, the goal is to understand their underlying inner workings, master pointer arithmetic, understand memory management (allocation and deallocation), and build a solid foundation for future 42 assignments.

---
## Instructions

### Prerequisites
To compile and use this library, you need a C compiler (`cc` or `gcc`) and the standard `make` utility tools.

### Compilation
The Makefile compiles everything with `-Wall -Wextra -Werror`.

* Build the library:
```bash
make
```
* Remove object files:
```bash
make clean
```
* Remove object files and the library archive:
```bash
make fclean
```
* Rebuild everything from scratch:
```bash
make re
```

### Usage
To use Libft in another project:

1. Include the header:
```c
#include "libft.h"
```
2. Link the library when compiling:
```bash
cc -Wall -Wextra -Werror main.c libft.a -o my_program
```

---
## Resources
* `man`
* extensive documentation on the C standard library on [cppreference](https://en.cppreference.com/w/c)
* article on input/output stream [GeeksforGeeks: Basic Input and Output in C](https://www.geeksforgeeks.org/c/basic-input-and-output-in-c/)
* specialized community threads for troubleshooting on [Stack Overflow](https://stackoverflow.com/)

---
## Library Overview & Detailed Description
The library has three parts: reimplemented libc functions, extra functions, and a linked list module.

### Part 1: Libc Functions
Same behavior as their standard counterparts, just prefixed with `ft_`.

**Character checks:**
* `ft_isalpha` – is it a letter?
* `ft_isdigit` – is it a digit (0-9)?
* `ft_isalnum` – is it a letter or digit?
* `ft_isascii` – is it a valid ASCII character?
* `ft_isprint` – is it printable (visible on screen)?

**Case conversion:**
* `ft_toupper` – lowercase to uppercase
* `ft_tolower` – uppercase to lowercase

**Strings:**
* `ft_strlen` – length of a string
* `ft_strchr` – find first occurrence of a char in a string
* `ft_strrchr` – find last occurrence of a char in a string
* `ft_strncmp` – compare two strings up to n bytes
* `ft_strnstr` – find a substring within a string, up to n bytes
* `ft_strlcpy` – copy a string, size-bounded
* `ft_strlcat` – concatenate a string, size-bounded
* `ft_atoi` – convert a string to an int

**Memory:**
* `ft_memset` – fill memory with a given byte
* `ft_bzero` – fill memory with zeros
* `ft_memcpy` – copy memory (no overlap)
* `ft_memmove` – copy memory (overlap safe)
* `ft_memchr` – find a byte in memory
* `ft_memcmp` – compare two memory areas byte by byte

**Allocation:**
* `ft_calloc` – allocate zeroed memory
* `ft_strdup` – duplicate a string into newly allocated memory

### Part 2: Additional functions
These functions are either absent from standard libc or implemented in an altered, specialized format:

* `ft_substr` – get a substring from an index up to a max length
* `ft_strjoin` – join two strings into a new one
* `ft_strtrim` – trim given characters from both ends of a string
* `ft_split` – split a string into an array using a delimiter
* `ft_itoa` – turn an int into a string
* `ft_strmapi` – apply a function to each char (with index), building a new string
* `ft_striteri` – apply a function to each char (with index), modifying in place
* `ft_putchar_fd` – write a char to a file descriptor
* `ft_putstr_fd` – write a string to a file descriptor
* `ft_putendl_fd` – write a string + newline to a file descriptor
* `ft_putnbr_fd` – write an int to a file descriptor

### Part 3: Bonus – Linked Lists
A linked list structure, `t_list`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

* `ft_lstnew` – create a new node
* `ft_lstadd_front` – add a node to the front of the list
* `ft_lstsize` – count the nodes in a list
* `ft_lstlast` – get the last node
* `ft_lstadd_back` – add a node to the end of the list
* `ft_lstdelone` – free one node and its content
* `ft_lstclear` – free an entire list
* `ft_lstiter` – apply a function to every node's content
* `ft_lstmap` – apply a function to every node and build a new list from the results