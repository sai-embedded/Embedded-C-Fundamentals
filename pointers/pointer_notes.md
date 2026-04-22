# Q1: Who determines the integer size and pointer size on any CPU architecure: 
    CPU vs C compiler? 


Pointer is a number (address) of a memory location.
pointers are of types:
1. data pointers (data type mentioned): pointers pointing to a data with a known data types. ex: int *i; float *f; char *c; struct xyz *t; 
2. function pointers: dereferncing a func pointer is like executing a func call. 
3. void pointers: number/address pointing to memory and without info on what type of data its pointing to. Dereferencing a void *ptr is not possible because cpu doesn't know what type of data it is refering to.