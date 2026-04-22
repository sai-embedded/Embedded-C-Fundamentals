Array: elements of same data type arranged next to each other. 

char var = 'A'; // char is 1 byte long. 'A' is stored into memory using its ASCII value. 

String : array of chars within "xyz". stored in contiguous memory. string is special type of array.
    "Hi" -> 'H', 'i', '\0'
every string is terminated by a null char. so elements in string here is 3. For an array of chars to become a string, arrays last element must be terminated by a NULL char. 

# char *str = "Hi"; // string variable is a char pointer. sizeof str is 4/8bytes depending on the machine
# char var = 'A'; // size of var is 1byte
* A char pointer represents a string holding the address of the first char. 

# int arr[5] ={1,2,3,4,5}; // 5 elements * 4 bytes each = 20 bytes 
* Should not access array elements outside the bounds, else prints garbage values.