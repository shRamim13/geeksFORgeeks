class Solution
{
public:
    // Function to find position of first set bit in the given number.
    int getFirstSetBit(int n)
    {
        int indx = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & (1 << i))
            {
                indx = i + 1;
                break;
            }
        }
        return indx;
    }
};