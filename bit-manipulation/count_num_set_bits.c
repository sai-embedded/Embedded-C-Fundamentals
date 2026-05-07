/*
“I can either scan all bit positions using masks or 
repeatedly check the least significant bit and right shift the number.”
1. Method 1: check every bit position if is set to 1. 0->31 (32bit int)
2. Method 2: instead of checking all 32 bits,
    * check last bit
    * right shift number
*/
int countSetBitsLoopBits(int x)
{
    int count = 0;

    for (int i = 0; i < 32; i++)
    {
        if (x & (1 << i))
        {
            count++;
        }
    }

    return count;
}

int countSetBitsShiftRight(int x)
{
    int count = 0;

    while (x)
    {
        if (x & 1)
        {
            count++;
        }

        x = x >> 1;
    }

    return count;
}