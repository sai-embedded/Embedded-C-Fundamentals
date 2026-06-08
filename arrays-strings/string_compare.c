
#include <stdio.h>
#include <string.h>

// Goal is to compare 2 strings fully and return an integer value based on the comparison
// strcmp() must return 0 if the strings are equal, a positive value if s1 is greater than s2, and a negative value if s1 is less than s2.
// Therfore, strcmp() must return the difference between the first non-matching characters in s1 and s2, or 0 if the strings are equal.
// Strcmp() must return int to support negative values, zero, and positive values.
int my_strcmp(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        return -999; // or any other value to indicate error
    }

    while (*s1 && (*s1 == *s2)) // while( (*s1 != '\0') && (*s1 == *s2) ) )
    {
        s1++;
        s2++;
    }

    return (unsigned char)*s1 - (unsigned char)*s2;
}

/*
Why does strcmp return int instead of char?
Because the comparison result must represent negative, zero, or positive values.
Arithmetic on characters is promoted to int anyway, and using int avoids overflow
and preserves ordering information.

*/
int main(void)
{
    char s1[] = "hey";
    char s2[] = "hello";

    // using library function
    int strncmp_out = strncmp(s1, s2, strlen(s1));
    // NOTE: Pass exactly the number of characters you want compared.

    if (strncmp_out == 0)
    {
        printf("Strings are equal\n");
    }
    else if (strncmp_out > 0)
    {
        printf("String s1 is greater than s2\n");
    }
    else
    {
        printf("String s1 is less than s2\n");
    }

    int my_strcmp_out = my_strcmp(s1, s2);
    if (my_strcmp_out == 0)
    {
        printf("Strings are equal\n");
    }
    else if (my_strcmp_out > 0)
    {
        printf("String s1 is greater than s2\n");
    }
    else
    {
        printf("String s1 is less than s2\n");
    }

    printf("strcmp_out = %d\n", strcmp("hel", "hello"));

    // char signed vs unsigned comparisions
    char c = 200;
    // char sometimes can be signed or unsigned depending on the implementation,
    // If char is signed and 200 exceeds the range of signed char (-128 to 127),
    // so it may wrap around to a negative value if char is signed.
    // If char is unsigned (Range 0-200), it will store the value as is (200).
    // Therefore, the output of printf("%d\n", c); can vary based on whether char is signed or unsigned in the implementation.
    printf("%d\n", c);

    return 0;
}

/*
* char s1[] = {}; VALID BUT AVOID: Is compiler dependent not standard.
* char s1[] = {0}; VALID: creates a '\0' only; length = 0; size = 1;
* char s1[] = "\0"; VALID: creates a '\0' only; length = 0; size = 1;
* char s1[] = '\0'; INVALID: because '\0' is a char not a string, is a char
* char s1[] = ""; VALID: contains '\0' only; length = 0; size = 1;
* char s1[] = NULL; INVALID: NULL Is a pointer constant not string initializer
* char *s1 = NULL; VALID: pointer points nowhere

Ex:
* char s = '\0'; VALID
* char str[] = '\0'; Error: INVALID initializer: char -> string
* char str1[] = {}; VALID BUT AVOID
*/