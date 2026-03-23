#include <stdio.h>

void main()
{
    char c = 'A';
    int i = 10;
    float f = 1.0;
    long long int li = 100;

    char *cp = &c;
    int *ip = &i;
    float *fp = &f;
    long long int *lip = &li;

    // size of pointer on this machine is 8bytes 
    printf("sizeof(cp) = %lu, sizeof(ip) = %lu, sizeof(fp) = %lu, sizeof(lip) = %lu\n",
        sizeof(cp), sizeof(ip), sizeof(fp), sizeof(lip));

    // dereferencing pointed value -> gives size of variables that pointer pointed to 
    printf("sizeof(*cp) = %lu, sizeof(*ip) = %lu, sizeof(*fp) = %lu, sizeof(*lip) = %lu\n",
        sizeof(*cp), sizeof(*ip), sizeof(*fp), sizeof(*lip));

    printf("Before deref: *cp = %c, *ip = %d, *fp = %0.1f, *lip = %lld\n", *cp, *ip, *fp, *lip);
    // dereference operations
    *cp = 'C';
    *ip = 20 + *ip;
    *fp = 1.0 + *fp;
    *lip = 2**lip - 1;

    printf("After deref: *cp = %c, *ip = %d, *fp = %0.1f, *lip = %lld\n", *cp, *ip, *fp, *lip);

}