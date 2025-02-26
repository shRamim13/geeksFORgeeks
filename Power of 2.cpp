class Solution
{
public:
    bool isPowerofTwo(int n)
    {
        // if (n > 0) {

        // }
        // return false;
        return (n & (n - 1)) == 0;
    }
};
