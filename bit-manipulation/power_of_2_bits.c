/*
* Powers of 2 in binary:
1   = 0001
2   = 0010
4   = 0100
8   = 1000
16  = 10000

* Notice: ONLY ONE BIT is set

* What Happens When we Subtract 1?
* Example:
    x = 8 (decimal) = 1000 (binary)
    Subtract 1: x=x-1
    7 = 0111

* When subtracting 1 in binary:
    * first 1 becomes 0
    * all bits to the right become 1
* Now AND (&) Them-> result = 0
Because:original number had only ONE set bit
subtracting 1 clears that bit and fills lower bits with 1s
no positions overlap anymore

* Now Try Non-Power-of-2
Example:
10 = 1010
9  = 1001

AND:
1010
1001
----
1000

Result = Not zero
Because: more than one set bit existed

* if (x & (x - 1)) == 0 -> means only one bit was set

* Important Edge Case: 0 Not power of 2, But: 0 & (-1) = 0 would incorrectly pass.
if (x > 0 && (x & (x - 1)) == 0)
{
    printf("Power of 2");
}
* “A power of 2 has exactly one set bit. 
Subtracting 1 flips all lower bits, so ANDing them results in 0.”
*/