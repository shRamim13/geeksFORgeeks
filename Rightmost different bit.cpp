
class Solution
{
public:
    // Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        if (m == n)
        {
            return -1;
        }
        int indx = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((m & (1 << i)) != (n & (1 << i)))
            {
                indx = i + 1;
                break;
            }
        }
        return indx;
    }
};

/*

class Solution {
  public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k) {
        return(n&(1<<k));
    }
};

*/