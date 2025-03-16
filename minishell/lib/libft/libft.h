/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:39:24 by kmartin           #+#    #+#             */
/*   Updated: 2024/06/13 11:03:39 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Includes prototypes for all mandatory libft library functions, along with
//  the structure definition and prototypes for the linked list bonus functions.
// Also includes the prototype for ft_printf (to allow its use when included).

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

// See optional module in dir FT_PRINTF
// Recreates the functionality of the original 'printf' function:
// outputs formatted strings according to provided flags.
int		ft_printf(const char *format, ...);

// See optional module in dir GET_NEXT_LINE
// Returns lines read from a file descriptor (one line per call).
char	*get_next_line(int fd);

// LINKED LIST STRUCT FOR BONUS FUNCTIONS
// See bonus 'lst...' functions declared below.
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// BONUS FUNCTION ft_lstnew
/**
 * @brief Creates a new node in a linked list.
 *
 * Allocates (with malloc(3)) and returns a new node.
 *
 * The member variable `content` is initialized with the value of the parameter 
 * `content`. The variable `next` is initialized to NULL
 *
 * @param content The content to create the node with.
 * @return The new node.
 *
 * @note Depends on malloc.
 */
t_list	*ft_lstnew(void *content);

// BONUS FUNCTION ft_lstadd_front
/**
 * @brief Adds the node `new` at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * @return None.
 *
 * @note No external dependencies.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

// BONUS FUNCTION ft_lstsize
/**
 * @brief Counts the number of nodes in a list.
 *
 * @param lst The beginning of the list.
 * @return The length of the list.
 *
 * @note No external dependencies.
 */
int		ft_lstsize(t_list *lst);

// BONUS FUNCTION ft_lstlast
/**
 * @brief Returns the last node of the list.
 *
 * @param lst The beginning of the list.
 * @return Last node of the list
 *
 * @note No external dependencies.
 */
t_list	*ft_lstlast(t_list *lst);

// BONUS FUNCTION ft_lstadd_back
/*
 * @brief Adds the node `new` at the end of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * @return None.
 *
 * @note No external dependencies.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

// BONUS FUNCTION ft_lstdelone
/**
 * @brief Deletes a node.
 *
 * Takes as a parameter a node and frees the memory of the node’s content using
 * the function `del` given as a parameter and free the node. The memory of
 * `next` must not be freed.
 *
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 * @return None.
 *
 * @note Depends on free.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

// BONUS FUNCTION ft_lstclear
/**
 * @brief Deletes a sequence of nodes.
 *
 * Deletes and frees the given node and every successor of that node, using the
 * function `del` and free(3).
 * Finally, the pointer to the list must be set to NULL.
 *
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the node.
 * @return None.
 *
 * @note Depends on free.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

// BONUS FUNCTION ft_lstiter
/**
 * @brief Applies a function to each node.
 *
 * Description Iterates the list ’lst’ and applies the function `f` on the
 * content of each node.
 *
 * @param f The address of the function used to iterate on the list.
 * @param lst The address of a pointer to a node.
 * @return None.
 *
 * @note No external dependencies.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

// BONUS FUNCTION ft_lstmap
/**
 * @brief Makes a new list by applying a function to each node.
 *
 * Iterates the list `lst` and applies the function `f` on the content of each
 * node. Creates a new list resulting of the successive applications of the
 * function ’f’. 
 * The ’del’ function is used to delete the content of a node if needed.
 *
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a node
 *  if needed.
 *
 * @return The new list.
 * @return NULL if the allocation fails.
 *
 * @note Depends on malloc and free.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// FUNCTION ft_isalpha (recreate libc function)
/**
 * @brief Checks for an alphabetic character.
 * 
 * The original function is part of the <ctype.h> standard library. 
 * Equivalent to (isupper(c) || islower(c)).
 * 
 * @param c An int; must have the value of an unsigned char or EOF.
 * @return The values returned are nonzero if the character c falls into the
 *  tested class.
 * @return  Zero if not.
 * 
 * @note No external dependencies allowed.
 */
//int		isalpha(int c);
int		ft_isalpha(int c);

// FUNCTION ft_isdigit (recreate libc function)
/**
 * @brief Checks for a digit (0 through 9).
 * 
 * The original function is part of the <ctype.h> standard library.
 * 
 * @param c An int; must have value of an unsigned char or EOF.
 * @return The values returned are nonzero if the character c falls into the
 *  tested class.
 * @return  Zero if not.
 * 
 * @note No external dependencies allowed.
 */
//int		isdigit(int c);
int		ft_isdigit(int c);

// FUNCTION ft_isalnum (recreate libc function)
/**
 * @brief Checks for an alphanumeric character.
 * 
 * The original function is part of the <ctype.h> standard library.
 * Equivalent to (isalpha(c) || isdigit(c)).
 * 
 * @param c An int; must have value of an unsigned char or EOF.
 * @return The values returned are nonzero if the character c falls into the
 *  tested class.
 * @return  Zero if not.
 * 
 * @note No external dependencies allowed.
 */
//int		isalnum(int c);
int		ft_isalnum(int c);

// FUNCTION ft_isascii (recreate libc function)
/**
 * @brief Checks whether c is a 7-bit unsigned char value that fits into the
 *  ASCII character set.
 * 
 * The original function is part of the <ctype.h> standard library.
 * 
 * @param c An int; must have value of an unsigned char or EOF.
 * @return The values returned are nonzero if the character c falls into the
 *  tested class.
 * @return  Zero if not.
 * 
 * @note No external dependencies allowed.
 */
//int		isascii(int c);
int		ft_isascii(int c);

// FUNCTION ft_isprint (recreate libc function)
/**
 * @brief Checks for any printable character including space.
 * 
 * The original function is part of the <ctype.h> standard library.
 * 
 * @param c An int; must have value of an unsigned char or EOF.
 * @return The values returned are nonzero if the character c falls into the
 *  tested class.
 * @return  Zero if not.
 * 
 * @note No external dependencies allowed.
 */
//int		isprint(int c);
int		ft_isprint(int c);

// FUNCTION ft_strlen (recreate libc function)
/**
 * @brief Calculate the length of a string.
 * 
 * The original function is part of the <string.h> standard library.
 * 
 * @param s A string.
 * @return The number of bytes in the string pointed to by s.
 * 
 * @note No external dependencies allowed.
 */
//size_t strlen(const char *s);
size_t	ft_strlen(const char *str);

// FUNCTION ft_memset (recreate libc function)
/**
 * @brief Fill memory with a constant byte.
 * 
 * The original function is part of the <string.h> standard library.
 * The memset() function fills the first n bytes of the memory area pointed to
 *  by s with the constant byte c.
 * 
 * @param s A pointer.
 * @param c An int that represents the constant byte to use.
 * @param n The number of bytes of memory to fill.
 * @return A pointer to the memory area s.
 * 
 * @note No external dependencies allowed.
 */
//void	*memset(void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);

// FUNCTION ft_bzero (recreate libc function)
/**
 * @brief Zero a byte string.
 * 
 * The original function is part of the <strings.h> UNIX library (not the
 *  standard C library).
 * The bzero() function erases the data in the n bytes of the memory starting at
 *  the location pointed to by s, by writing zeros (bytes containing '\0') to
 *  that area.
 * 
 * @param s A pointer to the memory location to be erased.
 * @param n Number of bytes of memory to be erased.
 * @return None.
 * 
 * @note No external dependencies allowed.
 */
//void	bzero(void *s, size_t n);
void	ft_bzero(void *s, size_t n);

// FUNCTION ft_memcpy (recreate libc function)
/**
 * @brief Copy memory area (overlaps not allowed).
 * 
 * The original function is part of the <string.h> standard library.
 * Copies n bytes from memory area src to memory area dest.
 * The memory areas must not overlap.
 * 
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of byte to copy from src to dest.
 * @return A pointer to the dest memory area.
 * 
 * @note No external dependencies allowed.
 */
//void	*memcpy(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);

// FUNCTION ft_memmove (recreate libc function)
/**
 * @brief Copy memory area (overlaps allowed).
 * 
 * The original function is part of the <string.h> standard library.
 * The  memmove()  function  copies  n bytes from memory area src to memory area
 *  dest. 
 * The memory areas may overlap: copying takes place as though the bytes in src
 *  are first copied into a temporary array that does not overlap src or dest,
 *  and the bytes are then copied from the temporary array to dest.
 * 
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of byte to copy from src to dest.
 * @return A pointer to the dest memory area.
 * 
 * @note No external dependencies allowed.
 */
//void	*memmove(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

// FUNCTION ft_strlcpy (recreate libc function)
/**
 * @brief Size-bounded string copying.
 * 
 * The original function is part of the <string.h> standard library.
 * Copies up to size - 1 characters from the NUL-terminated string src to dst,
 *  NUL-terminating the result.
 * Takes the full size of the buffer (not just the length) and guarantee to
 *  NUL-terminate the result (as long as size is larger than 0).
 * Note that a byte for the NUL should be included in size.
 * Note src must be NUL-terminated (a true C string).
 * 
 * @param dst A pointer to the destination string.
 * @param src A pointer to the source string.
 * @param size The full size of the buffer (including the NUL byte).
 * @return The total length of the string it tried to create (the length of
 *  src); this is to make truncation detection simple. 
 * 
 * @note No external dependencies allowed.
 */
//size_t strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// FUNCTION ft_strlcat (recreate libc function)
/**
 * @brief Size-bounded string concatenation.
 * 
 * The original function is part of the <string.h> standard library.
 * Appends the NUL-terminated string src to the end of dst.  It will append at
 *  most size - strlen(dst) - 1 bytes, NUL-terminating the result.
 * Takes the full size of the buffer (not just the length) and guarantee to
 *  NUL-terminate the result (as long as size is larger than 0, or as long as
 *  there is at least one byte free in dst).
 * Note that a byte for the NUL should be included in size.
 * Note both src and dst must be NUL-terminated (true C strings).
 * Note if strlcat() traverses size characters without finding a NUL, the length
 *  of the string is considered to be size and the destination string will not
 *  be NUL-terminated (since there was no space for the NUL).  This keeps
 *  strlcat() from running off the end of a string.  In practice this should not
 *  happen (as it means that either size is incorrect or that dst is not a
 *  proper “C” string).
 * 
 * @param dst A pointer to the destination string.
 * @param src A pointer to the source string.
 * @param size The full size of the buffer (including the NUL byte).
 * @return The total length of the string it tried to create (the length of dst
 *  plus the length of src); this is to make truncation detection simple. 
 * 
 * @note No external dependencies allowed.
 */
//size_t strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

// FUNCTION ft_toupper (recreate libc function)
/**
 * @brief Convert uppercase.
 * 
 * The original function is part of the <ctype.h> standard library.
 * If c is neither an unsigned char value nor EOF, the behavior of these
 *  functions is undefined.
 * 
 * @param c An int representing an ASCII letter (uppercase or lowercase).
 * @return The value of the converted letter.
 * @return c if the conversion was not possible.
 * 
 * @note No external dependencies allowed.
 */
//int		toupper(int c);
int		ft_toupper(int c);

// FUNCTION ft_tolower (recreate libc function)
/**
 * @brief Convert lowercase.
 * 
 * The original function is part of the <ctype.h> standard library.
 * If c is neither an unsigned char value nor EOF, the behavior of these
 *  functions is undefined.
 * 
 * @param c An int representing an ASCII letter (uppercase or lowercase).
 * @return The value of the converted letter.
 * @return c if the conversion was not possible.
 * 
 * @note No external dependencies allowed.
 */
//int		tolower(int c);
int		ft_tolower(int c);

// FUNCTION ft_strchr (recreate libc function)
/**
 * @brief Locate single-byte character in string (first occurrence).
 * 
 * The original function is part of the <string.h> standard library.
 * 
 * @param s Pointer to a string.
 * @param c Int representing the character to search for (ASCII byte value).
 * @return NULL if the character is not found.
 * @return A pointer to the matched character. The terminating null byte is
 *  considered part of the string, so that if c is specified as '\0' it will
 *  return a pointer to the terminator.
 * 
 * @note No external dependencies allowed.
 */
//char *strchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);

// FUNCTION ft_strrchr (recreate libc function)
/**
 * @brief Locate single-byte character in string (last occurrence).
 * 
 * The original function is part of the <string.h> standard library.
 * 
 * @param s Pointer to a string.
 * @param c Int representing the character to search for (ASCII byte value).
 * @return NULL if the character is not found.
 * @return A pointer to the matched character. The terminating null byte is
 *  considered part of the string, so that if c is specified as '\0' it will
 *  return a pointer to the terminator.
 * 
 * @note No external dependencies allowed.
 * 
 */
//char *strrchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

// FUNCTION ft_strncmp (recreate libc function)
/**
 * @brief Compare two strings (up to n bytes).
 * 
 * The original function is part of the <string.h> standard library.
 * The return value is the arithmetic result of subtracting the last compared
 *  byte in s2 from the last compared byte in s1.
 * The comparison stops when a difference is found, or if a string NUL
 *  terminator is found (verify).
 * 
 * @param s1 Pointer to string1.
 * @param s2 Pointer to string 2.
 * @param n The number of bytes to compare.
 * @return 0 if s1==s2.
 * @return A negative value if s1<s2.
 * @return A positive value if s1>s2 (only looking at the first n bytes).
 * 
 * @note No external dependencies allowed.
 */
//int		strncmp(const char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// FUNCTION ft_memchr (recreate libc function)
/**
 * @brief Scan memory area for first instance of a character.
 * 
 * The original function is part of the <string.h> standard library.
 * 
 * @param s A pointer to the memory area to search.
 * @param c An int representing the character to search for.
 * @param n The number of bytes of memory to search.
 * @return A pointer to the matching byte or NULL if the character does not
 *  occur in the given memory area.
 * 
 * @note No external dependencies allowed.
 */
//void	*memchr(const void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

// FUNCTION ft_memcmp (recreate libc function)
/**
 * @brief Compare contents of two memory areas.
 * 
 * The original function is part of the <string.h> standard library.
 * The return value is the arithmetic result of subtracting the last compared
 *  byte in s2 from the last compared byte in s1.
 * The comparison stops when a difference is found.
 * 
 * @param s1 Pointer to memory area 1.
 * @param s2 Pointer to memory area 2.
 * @param n The number of bytes to compare.
 * @return 0 if s1==s2.
 * @return A negative value if s1<s2.
 * @return A positive value if s1>s2 (only taking into account the first n
 *  bytes).
 * 
 * @note No external dependencies allowed.
 */
//int		memcmp(const void *s1, const void *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// FUNCTION ft_strnstr (recreate libc function)
/**
 * @brief Locate a substring in a defined initial portion of a string.
 * 
 * The original function is part of the <string.h> standard library.
 * Locates the first occurrence of the null-terminated string little in the
 *  string big, where not more than len characters are searched.
 * Characters that appear after a ‘\0’ character are not searched.
 * 
 * @param big A pointer to the string to be searched.
 * @param little A pointer to the null-terminated substring to find.
 * @param len The maximum number of characters to search.
 * @return If little is an empty string, big is returned.
 * @return If little occurs nowhere in big, NULL is returned.
 * @return If little is found it its entirety, a pointer to the first character
 *  of the first occurrence of little is returned.
 * 
 * @note No external dependencies allowed.
 * 
 */
//char *strnstr(const char *big, const char *little, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);

// FUNCTION ft_atoi (recreate libc function)
/**
 * @brief Convert an ASCII string of numbers to an integer.
 * 
 * The original function is part of the <stdlib.h> standard library.
 * Converts the initial portion of the string pointed to by nptr (stopping at
 *  the null-terminator or the first non-digit character) to int.
 * The string may begin with an arbitrary amount of white space (as determined by
 *  isspace(3)) followed by a single optional '+' or '-' sign.
 * No checks for overflow or underflow are done.
 * Only base-10 input can be converted.
 * 
 * @param nptr A pointer to a string.
 * @return The converted value.
 * @return 0 on error (note there is no way to distinguish between 0 as an error
 *  and as a converted value).
 * 
 * @note No external dependencies allowed.
 */
//int		atoi(const char *nptr);
int		ft_atoi(const char *nptr);

// FUNCTION ft_calloc (recreate libc function)
/**
 * @brief Allocate memory for an array.
 * 
 * The original function is part of the <stdlib.h> standard library.
 * Allocates memory for an array of nmemb elements of size bytes each and
 *  returns a pointer to the allocated memory.  The memory is set to zero.
 * The original function can fail with an error ‘ENOMEM Out of memory’ under some
 *  conditions.
 * 
 * @param nmemb The number of elements in the array.
 * @param size The number of bytes needed for each element of the array.
 * @return If nmemb or size is 0, then returns either NULL, or a unique pointer
 *  value that can later be successfully passed to free().
 * @return If nmemb x size would result in integer overflow, then returns an
 *  error (NULL).
 * Otherwise, returns a pointer to the allocated memory.
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//void	*calloc(size_t nmemb, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);

// FUNCTION ft_strdup (recreate libc function)
/**
 * @brief Duplicate a string.
 * 
 * The original function is part of the <string.h> standard library.
 * Memory for the duplicate string is obtained with malloc(), and can be freed
 *  with free().
 * 
 * @param s A pointer to a string.
 * @return A pointer to a new string which is a duplicate of the string s.
 * @return If insufficient memory is available, returns NULL and sets errno to
 *  indicate the cause of the error (‘ENOMEM’; insufficient memory available to
 *  allocate duplicate string).
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//char *strdup(const char *s);
char	*ft_strdup(const char *s);

// FUNCTION ft_substr (novel function)
/**
 * @brief Extracts a substring of a given length from a given start position.
 * 
 * Allocates with malloc() and returns a substring from the string s.
 * The substring begins at index ‘start’ and is of maximum size ‘length’.
 * 
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string s.
 * @param len The maximum length of the string.
 * @return The substring.
 * @return NULL if the allocation fails.
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//char *ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// FUNCTION ft_strjoin (novel function)
/**
 * @brief Concatenates two strings and returns a new string.
 * 
 * Allocates with malloc() and returns a new string, which is the result of the
 *  concatenation of ‘s1’ and ‘s2’.
 * 
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string.
 * @return NULL if the allocation fails.
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//char *ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);

// FUNCTION ft_strtrim (novel function)
/**
 * @brief Trims a string with reference to a set of characters to remove from the
 *  start and end.
 * 
 * Allocates with malloc() and returns a copy of ‘s1’ with the characters
 *  specified in ‘set’ removed from the beginning and the end of the string.
 * 
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string.
 * @return NULL if the allocation fails.
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//char *ft_strtrim(char const *s1, char const *set);
char	*ft_strtrim(char const *s1, char const *set);

// FUNCTION ft_split (novel function)
/**
 * @brief Splits a string into multiple substrings based on a delimiter.
 * 
 * Allocates with malloc() and returns an array of strings obtained by splitting
 *  ‘s’ using the character ‘c’ as a delimiter. The array must end with a NULL
 *  pointer.
 * 
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 * @return NULL if the allocation fails.
 * 
 * @note Depends on malloc() and free() from <stdlib.h>.
 */
//char **ft_split(char const *s, char c);
char	**ft_split(char const *s, char c);

// FUNCTION ft_itoa (novel function)
/**
 * @brief Convert a positive or negative integer into an ASCII string.
 * 
 * Allocates with malloc() and returns a string representing the integer received
 *  as an argument. Negative numbers must be handled.
 * 
 * @param n The integer to convert.
 * @return The string representing the integer.
 * @return NULL if the allocation fails.
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//char *ft_itoa(int n);
char	*ft_itoa(int n);

// FUNCTION ft_strmapi (novel function)
/**
 * @brief Applies another function to each character of a string,  returning a
 *  new string.
 * 
 * Applies the function ‘f’ to each character of the string ‘s’, and passing its
 *  index as first argument to create a new string with malloc() resulting from
 *  successive applications of ‘f’.
 * 
 * @param s The string on which to iterate.
 * f The function to apply to each character.
 * @return The string created from the successive applications of ‘f’.
 * @return NULL if the allocation fails.
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// FUNCTION ft_striteri (novel function)
/**
 * @brief Applies another function to each character of a string, modifying them
 *  in place.
 * 
 * Applies the function ‘f’ on each character of the string passed as argument,
 *  passing its index as first argument. Each character is passed by address to
 *  ‘f’ to be modified if necessary.
 * 
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return None.
 * 
 * @note No external dependencies allowed.
 */
//void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// FUNCTION ft_putchar_fd (novel function)
/**
 * @brief Outputs a character to a specified file descriptor.
 * 
 * Outputs the character ‘c’ to the given file descriptor.
 * 
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 * @return None.
 * 
 * @note Depends on write() from <unistd.h>.
 */
//void	ft_putchar_fd(char c, int fd);
void	ft_putchar_fd(char c, int fd);

// FUNCTION ft_putstr_fd (novel function)
/**
 * @brief Outputs a string to a specified file descriptor.
 * 
 * Outputs the string ‘s’ to the given file descriptor.
 * 
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * @return None.
 * 
 * @note Depends on write() from <unistd.h>.
 */
//void	ft_putstr_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);

// FUNCTION ft_putendl_fd (novel function)
/**
 * @brief Outputs a string followed by a newline to a specified file descriptor.
 * 
 * Outputs the string ‘s’ to the given file descriptor followed by a newline.
 * 
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * @return None.
 * 
 * @note Depends on write() from <unistd.h>.
 */
//void	ft_putendl_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

// FUNCTION ft_putnbr_fd (novel function)
/**
 * @brief Outputs an integer to a specified file descriptor.
 * 
 * Outputs the integer ‘n’ to the given file descriptor.
 * 
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 * @return None.
 * 
 * @note Depends on write() from <unistd.h>.
 */
//void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif // LIBFT_H
