#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *p[3];

    for(int i=0; i<3; i++)
    {
        p[i] = malloc(sizeof(i));
        *p[i] = i+1;
        printf("&p[%d]=%p\n", i, &p[i]);
        printf("*p[%d]=%d\n", i, *p[i]);
    }
    
    printf("sizeof(p) = %lu\n", sizeof(p));

    for(int i=0; i<3; i++)
    {
        free(p[i]);
    }
}