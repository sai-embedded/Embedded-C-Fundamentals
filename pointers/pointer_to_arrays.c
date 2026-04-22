#include <stdio.h>

void main()
{
    // 1. similarity between an array and a pointer 
    char *name_ptr = "Shruthi"; // even though is pointing to first char address, sizeof gives the ptr size on the machine.
    char name_arr[] = "Shruthi"; // sizeof includes NULL char can be noticed while printing 

    printf("name-ptr = %s, &name-ptr = %p, name-ptr-value = %c \n", name_ptr, name_ptr,  *name_ptr);
    printf("name-arr = %s, &name-arr = %p, *name-arr = %c \n", name_arr, name_arr, *name_arr);

    // 2. differences between an array and a pointer 
    printf("sizeof(name_ptr) = %lu, sizeof(name_arr) = %lu \n", sizeof(name_ptr), sizeof(name_arr));

    int int_arr[] = {1, 2, 3}; // sizeof(int_arr) gives the size for entire array 3elements*4bytes each = 12bytes
    int *int_ptr = int_arr; // same as &int_arr; sizeof(int_ptr) gives 8bytes ie size of pointer on that machine (64bit)

    printf("sizeof(int_arr) = %lu, sizeof(int_ptr) = %lu \n", sizeof(int_arr), sizeof(int_ptr));


    // NOTE: pointer and array both are treated as addresses but when asked sizes 
    // sizeof on an array returns the size of all the elements together in memory
    // ie number of bytes stored in the memory for the entire array
    // sizeof on a pointer returns how many bytes needed to store the address  

    // 3. array cannot be reassigned to another address but pointer can
    // array elements can be rearranged though
    int arr1[]  = {10,11,12};
    int arr2[] = {13,14,15};
    // arr2 = arr1; // this cannot happen. error: assignment to expression with array type
    // int var = 5;
    // arr1 = &var; // this cannot happen as well so array cannot be reassigned to any other memory address.
    int *ptr = arr1;
    printf("*ptr to arr1 = %d\n",*ptr);
    ptr = arr2; // this is possible 
    printf("*ptr to arr2 = %d\n",*ptr);
}