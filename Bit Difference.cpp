class Solution
{
public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b)
    {
        int cnt = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((a & (1 << i)) != (b & (1 << i)))
            {
                cnt++;
            }
        }
        return cnt;
    }
};
