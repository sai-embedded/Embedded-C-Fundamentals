#include <stdio.h>

int main()
{
    char var = 'A'; // var is a char variable 
    printf("sizeof(var) = %ld\n", sizeof(var)); // 1 byte
    printf("var=%c\n", var);

    char *str = "Hi"; // str is a pointer holds the address of a char -> char pointer 
    printf("sizeof(str) = %ld\n", sizeof(str)); // 8 since i am on a 64bit machine
    printf("sizeof(Hi) = %ld\n", sizeof("Hi")); 
    printf("str=%s\n", str);

    return 0;
}