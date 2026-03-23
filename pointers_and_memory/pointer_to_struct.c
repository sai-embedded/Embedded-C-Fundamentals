#include <stdio.h>

struct my_struct {
    int a;
    float b;
    long long int c;
};

void main()
{
    struct my_struct var = {
        .a = 10,
        .b = 0.1,
        .c = 100,
    };
    printf("Struct init: var.a = %d, var.b = %f, var.c = %lld\n", var.a, var.b, var.c); 

    struct my_struct *ptr = &var;

    // deref a struct using M1 
    (*ptr).a = (*ptr).a + 1;
    (*ptr).b = (*ptr).b + 1;
    (*ptr).c = (*ptr).c + 1;

    printf("var.a = %d, var.b = %f, var.c = %lld\n", var.a, var.b, var.c);
    printf("(*ptr).a = %d, (*ptr).b =%f, (*ptr).c = %lld\n", (*ptr).a, (*ptr).b, (*ptr).c);

    // deref a struct M2 
    ptr->a = ptr->a + 1;
    ptr->b = ptr->b + 1;
    ptr->c = ptr->c + 1;
    printf("ptr->a = %d, ptr->b =%f, ptr->c = %lld\n", ptr->a, ptr->b, ptr->c);

    // NOTE: syntax (*ptr).a is equal to ptr->a
}