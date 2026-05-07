/* if ((x & 1) == 0)
{
    printf("Even");
}
else
{
    printf("Odd");
}

* Odd number -> Last bit = 1
Example:
5 = 0101
0101
0001
----
0001  -> non-zero -> odd

* Even number -> Last bit = 0
Example:
6 = 0110
0110
0001
----
0000 -> even

* “The least significant bit determines parity. If LSB is 1, the number is odd; otherwise even.” */