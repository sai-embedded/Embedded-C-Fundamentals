#include <stdio.h>

void main()
{
    // 1. Pointer creation, printing values and addresses
    char a = 'A'; // create a variable
    char *a_ptr = &a; // create a pointer variable 'a_ptr' storing address of variale 'a'

    printf("a=%c, &a=%p\n", a, &a);
    printf("a_ptr=%p, &a_ptr=%p, *a_ptr=%c\n", a_ptr, &a_ptr, *a_ptr);

    // NOTEs:
    /*
    int x = 0xAA;
    int *x_ptr = &x;
    printf("x&x_ptr = %d\n", x&x_ptr); // provides error: invalid operands to binary & (have ‘int’ and ‘int *’)
    // We cannot perform '&' operations on a pointer with an integer
    // This can be achieved via other ways like casting a pointer to integer type
    // compiler would still complain sending a warning: cast from pointer to integer of different size
    // Refer the below example 2:
    */
    // 2. type cast a pointer to int
    int x = 0xff; // decimal value is 255
    int *x_ptr = &x;
    int x_out = x & (int)x_ptr; // & between 2 vars is treated as logical AND first. 
    printf("x= %x, &x = %p, x_ptr = %p\n", x, &x, x_ptr);
    printf("x&x_ptr = %x\n", x_out); // performing logical AND operation using a pointer and a integer

    /*
    NOTEs:
    On a 64-bit system, pointers are 8 bytes and int is 4 bytes, 
    so casting a pointer to an int on a 64bit system truncates the pointer upper MSB 4 bytes 
    so only the lower 32 bits (4Bytes) participate in the bitwise operation.
    #Refer table: 
        System	    int	        pointer
        ---------------------------------
        64-bit	    4	        8
        32-bit	    4	        4	
        16-bit	    2 (usually)	2 or 4	
        8-bit MCU	2 (usually)	2

    */

    // 3. use of a * with pointer vars
    int y = 2;
    int *y_ptr = &y;
    /*
    ERROR: we cannot multiply an integer with a pointer : invalid types
    int y_out = y * y_ptr; // * between 2 vars is firstly treated as logical OR operation.
    printf("y * y_ptr = %x\n", y_out); 
    */
    int y_out = y * *y_ptr; // NOTE: first * treated as multipler and second * is treated as dereference
    // (dereference meaning go to address stored in pointer and fetch the value)
    printf("y * y_ptr = %d\n", y_out);
    
    // pointer reference -> addresses
    // pointer derefernce -> value at address

    // TODO: 
    // a. try pointer to pointer & operations and other OR operations 
    // b. difference between &&, **  ex: x&&x_ptr, x&&x  
    // (first time compiler sees an & between 2 vars treated as logic AND and 
    // next time it sees around a var like &x is treated as address)
    // c. try more pointer arithmetic 

}
