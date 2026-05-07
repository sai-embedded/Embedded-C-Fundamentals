# Used: registers, GPIO pin config, flags, config bits

# Operations:
1. set bit -> make bit = 1
2. clear bit -> make bit = 0
3. toggle bit -> invert bit
4. check bit -> read bit

# Bitwise operators:
1. AND (&)
2. OR (|)
3. XOR (^)
4. NOT (!)
5. LEFT SHIFT (<<)
6. RIGHT SHIFT (>>)

# AND:
    0 & 0 -> 0
    0 & 1 -> 0
    1 & 0 -> 0
    1 & 1 -> 1

# OR:
    0 | 0 -> 0
    0 | 1 -> 1
    1 | 0 -> 1
    1 | 1 -> 1

# XOR:
    0 ^ 0 -> 0
    0 ^ 1 -> 1
    1 ^ 0 -> 1
    1 ^ 1 -> 0

* Set a specific bit to 1: x = x | (1 << pos);
* Clear a specific bit to 0: x = x & ~(1 << pos);
* Toggle bit: 1->0; 0->1 : x = x ^ (1 << pos); XOR with 1 flips bit
* Check bit: Read whether bit is set: if (x & (1 << pos)) Non-zero -> bit is SET

# “Why use bit manipulation in firmware?”
“Hardware registers are bit-oriented.
Bit masking is commonly used for hardware register control because
it allows modifying specific bits without affecting others.”
