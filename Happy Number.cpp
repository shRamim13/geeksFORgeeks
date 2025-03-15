class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            int mode = n % 10;
            sum += mode * mode;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int slow = n;
        int fast = getSum(n);
        while (fast != 1 && slow != fast)
        {
            slow = getSum(slow);
            fast = getSum(getSum(fast));
        }
        return fast == 1;
    }
};