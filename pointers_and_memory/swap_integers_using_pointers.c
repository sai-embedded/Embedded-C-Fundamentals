#include <stdio.h>
#include <stdlib.h>

/*
* Function call creates a stack frame, params stored in stack, and when it returns, that frame is popped.
* Pass by reference/pointer: address passed; changes affect original memory; pointer holds address of original variable.
* Pass by value: copy of var passed; changes donot affect original
*/

void swap(int *a, int *b) // arguments stored on stack
{
    // all stack variables life ends when func returns and stack frame is removed. 
    int tmp = *a; // stack var 
    *a = *b; 
    *b = tmp; 
}

typedef struct 
{
   int a;
   int b;
} swap_var_t;

int swap_vars_using_struct(swap_var_t *swap)
{
    int temp = swap->a;
    swap->a = swap->b;
    swap->b = temp;
    return 0;
}

int main()
{
    int a = 5; // local var goes to stack 
    int b = 10; // local stack var 
    // output a = 10; b = 5;
    
    printf("Before swap a=%d b=%d\n", a, b);

    // if we do swap by passing values, we would see a=5, b=10 since we just pass a copy of the 
    // variables not the actual variables reference so we pass addresses.
    swap(&a,&b); // func call stored on stack 
    // when swap returns, stack frame deleted, all its variables deleted
    // but since passed a, b addresses, we performed swap operations in their memory address.
    
    printf("After swap a=%d b=%d\n", a, b);

    // Pass struct creating 2 members and a pointer to struct to access members and swap them
    // swap_var_t *swap_ptr; // BUG: uninitialized pointer leads to crash; 
    // Option 1: use heap allocation
    swap_var_t *swap_ptr = malloc(sizeof(swap_var_t)); 
    /*
    OR Option2: 
    swap_var_t swap_var;  (OR) swap_var ={a,b};
    swap_var.a = a;
    swap_var.b = b;
    swap_vars_using_struct(&swap_var); 
    */ 
    // init struct members 
    swap_ptr->a = a;
    swap_ptr->b = b;

    printf("Before swap.a =%d swap.b=%d\n", swap_ptr->a, swap_ptr->b);
    swap_vars_using_struct(swap_ptr); // pass by reference 
    printf("After swap.a =%d swap.b=%d\n", swap_ptr->a, swap_ptr->b);

    return 0;
}

