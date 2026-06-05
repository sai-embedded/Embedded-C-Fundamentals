/*
* Imp: What's wrong with classic strcpy()?
* Ex:
char dest[5]; // includes '\0' char
char src[] = "hello welcome";
strcpy(dest, src);

Problem: dest has only 5 bytes available including NULL char
src is 14bytes long. As a result, writes beyond the dest buffer
causing overflow.
*/

#include <stdio.h>
#include <string.h>

/*
 * Safe string copy implementation.
 *
 * Copies at most (dest_size - 1) characters and
 * always NULL terminates the destination buffer.
 *
 * Parameters:
 *      dest      - destination buffer
 *      src       - source string
 *      dest_size - total size of destination buffer
 *
 * Returns:
 *      Number of characters copied
 *
 * Notes: Is my implementation safe for overlapping memory?
 * No. It behaves similarly to strcpy(). 
 * Source and destination must not overlap. 
 * If overlap is possible, use memmove()-style logic.
 */
size_t my_strcpy_safe(char *dest, const char *src, size_t dest_size)
{
    if (dest == NULL || src == NULL)
    {
        return 0;
    }

    if (dest_size == 0)
    {
        return 0;
    }

    size_t copied = 0;

    /*
     * Reserve one byte for terminating '\0'
     */
    while (*src != '\0' && copied < (dest_size - 1))
    {
        *dest = *src;

        dest++;
        src++;
        copied++;
    }

    *dest = '\0';

    return copied;
}

int main(void)
{
    char src[] = "hello welcome";
    char dest[5];

    size_t copied = my_strcpy_safe(dest, src, sizeof(dest));

    printf("Copied Characters = %zu\n", copied); // prints 4
    printf("Destination String using my_strcpy_safe = %s\n", dest); // prints "hell"

    char dest_cpy[5];
    strncpy(dest_cpy, src, sizeof(dest_cpy)); 
    dest_cpy[sizeof(dest_cpy) - 1] = '\0'; // IMP: strncpy does not always null terminate
    printf("Destination String using strncpy = %s\n", dest_cpy); 

    return 0;
}

/* Use Cases:
* 1. src > dest ?
src  = "hello welcome"
dest = 5 bytes
Result: h e l l \0
Truncated safely. No overflow.

* 2. src < dest ?
src  = "cat"
dest = 100 bytes
Result: c a t \0
Remaining bytes untouched. Perfectly fine.

* 3. src == dest No issue

*4. IMP: source and destination overlap
char str[] = "hello";

my_strcpy_safe(str + 1,
               str,
               sizeof(str) - 1);

For overlapping buffers: 
Ex:
Before
h e l l o \0
^
src

  ^
  dest

Now copying left-to-right corrupts data.
This is why: memcpy() requires. No overlap and memmove() exists.
*/