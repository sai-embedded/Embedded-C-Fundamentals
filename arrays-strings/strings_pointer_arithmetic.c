#include <stdio.h>

int main(void)
{
    char str[] = "APPLE";
    char *ptr = str;

    /*
    Pointer Arithmetic Example

    str = "APPLE"

    Memory Layout:
    str[0] = 'A'
    str[1] = 'P'
    str[2] = 'P'
    str[3] = 'L'
    str[4] = 'E'
    str[5] = '\0'

    ptr      -> &str[0]
    ptr + 2  -> &str[2]

    *(ptr + 2)
        = *(&str[2])
        = str[2]
        = 'P'

    *ptr
        = *(&str[0])
        = str[0]
        = 'A'

    *ptr + 2
        = 'A' + 2
        = 65 + 2
        = 67
        = 'C'

    NOTE:
    *(ptr + 2) and *ptr + 2 are completely different expressions.
    Parentheses change the order of evaluation.
    */

    printf("%c\n", *(ptr + 2)); // Prints: P
    printf("%c\n", *ptr + 2);   // Prints: C


    /*
    Character Arrays

    str1 and str2 are separate character arrays.

    Each array has its own copy of the string data.

    Typical memory layout for local variables:
        Stack Memory

    Memory:

    str1:
    H e l l o \0

    str2:
    H e l l o \0

    Arrays are modifiable:

        str1[0] = 'h';   // Valid
        str2[4] = 'A';   // Valid

    sizeof(str1) == 6
    sizeof(str2) == 6
    */

    char str1[] = "Hello";
    char str2[] = "Hello";


    /*
    Pointer to String Literal

    p1 and p2 are pointer variables stored on the stack.

    The string literal "Hello" is typically stored in the
    read-only data section (.rodata).

    Example:

        Stack:
            p1 ------+ 0x5000
                    
        .rodata: 0x5000
            "Hello\0"

    IMPORTANT:

    p1 is modifiable
        p1 = str1;       // Valid
        p1 = NULL;       // Valid

    The string literal being pointed to is NOT modifiable.

    Attempting to modify a string literal results in
    Undefined Behavior.

    Many systems will generate a segmentation fault,
    but the C standard only guarantees:
        "Undefined Behavior"

    Best practice:

        const char *p1 = "Hello";

    This prevents accidental modification.
    */

    char *p1 = "Hello";
    char *p2 = "Hello";

    // Undefined Behavior
    // Often crashes with Segmentation Fault
    // p1[0] = 'h';

    return 0;
}