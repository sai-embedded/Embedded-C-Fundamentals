#include <stdio.h>
#include <string.h>

/*
 * Calculate string length using array indexing.
 *
 * Returns:
 *     Number of characters in string
 *     (excluding terminating '\0')
 *
 * Example:
 *     "Hello" -> 5
 */
int my_strlen_array(const char *str)
{
    if (str == NULL)
    {
        return 0;
    }

    int len = 0;

    while (str[len] != '\0')
    {
        len++;
    }

    return len;
}

/*
 * Calculate string length using pointer arithmetic.
 *
 * Returns:
 *     Number of characters in string
 *     (excluding terminating '\0')
 *
 * Example:
 *     "Hello" -> 5
 */
int my_strlen_pointer(const char *str)
{
    if (str == NULL)
    {
        return 0;
    }

    int len = 0;

    while (*str)
    {
        len++;
        str++;
    }

    return len;
}

int main(void)
{
    char str[] = "shruthi1234";

    /*
     * Other test cases:
     *
     * char str[] = "";
     * char *str = NULL;
     */

    printf("Length using array indexing = %d\n",
           my_strlen_array(str));

    printf("Length using pointer arithmetic = %d\n",
           my_strlen_pointer(str));

    printf("Length using strlen() = %zu\n",
           strlen(str));

    /*
     * sizeof(str)
     *
     * Includes terminating NULL character.
     *
     * Example:
     *     "shruthi1234"
     *
     * Characters = 11
     * '\0'       = 1
     *
     * Total = 12 bytes
     */
    printf("sizeof(str) = %zu\n",
           sizeof(str));

    return 0;
}

/* Follow-up Q&As:
* Q1: is this while(str[str_len] != '\0') same as while(*str)?
* A:
Expression 1: uses Array indexing
while(str[str_len] != '\0')
--------->
str[0]
str[1]
str[2]
...
<--------

Expression 2: moves the pointer itself -> Pointer arithmetic.
while(*str)
{
    str++;
}
-------->
'A'
 ^
 str

'B'
 ^
 str

'C'
 ^
 str
<-------

* Q2: is str[i] equivalent to *(str + i)? 
* A: Yes: 
"str is an array. In most expressions it decays to a pointer 
to its first element (&str[0])."
str decays -> &str[0]
str + 2 -> &str[0] + 2 -> &str[2] 
Now *(str + 2) -> *&str[2] -> str[2]

* Q3: i[str] is valid or not?
* A: valid because str[i] means *(str+i) == *(i+str) which becomes i[str]
Example:    char str[] = "APPLE";
            printf("%c\n", str[2]); // prints 'P'
            printf("%c\n", 2[str]); // prints 'P'
            Both print the same thing...
*
*/