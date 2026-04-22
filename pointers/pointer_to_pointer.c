#include <stdio.h>

void main()
{
    // 1. "*" folowed by "&" cancels each other and gives only content of var 
    int x = 10;
    
    printf("x=%d, &x=%p, *&x=%d, *&*&*&x=%d\n", x, &x, *&x, *&*&*&x);

    *&x= 20;
    printf("x=%d\n", x);

    *&*&*&x = 30;
    printf("x=%d\n", x);

    // 2. pointer to pointer, double, triple pointers
    int i = 10;
    int *ip = &i;
    int **ipp = &ip;
    int ***ippp = &ipp;

    printf("&i=%p, &ip=%p, &ipp=%p, ippp=%p\n", &i, &ip, &ipp, ippp);
    printf("&i=%p, ip=%p, ipp=%p, ippp=%p\n", &i, ip, ipp, ippp);
}
