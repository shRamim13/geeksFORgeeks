class Solution
{
public:
    int toggleBits(int n, int l, int r)
    {
        int num = n;
        for (int i = l - 1; i < r; i++)
        {
            num = (num ^ (1 << i));
        }
        return num;
    }
};

/*
class Solution {
  public:
    int setKthBit(int n, int k) {
       return (n | (1 << (k)));// Ensure the k-th bit is set
    }
};

*/