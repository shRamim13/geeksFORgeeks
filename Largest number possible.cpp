class Solution
{
public:
    string findLargest(int n, int s)
    {
        if (s == 0 && n > 1)
            return "-1";
        string str = "";
        while (n)
        {
            for (int i = 9; i >= 0; i--)
            {
                if (s - i >= 0)
                {
                    str += (i + '0');
                    s = s - i;
                    break;
                }
            }
            n--;
        }
        return s == 0 ? str : "-1";
    }
};