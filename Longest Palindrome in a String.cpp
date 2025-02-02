class Solution
{
public:
    int mem[1001][1001];

    int solve(string s, int i, int j)
    {
        if (i >= j)
        {
            return 1;
        }
        if (mem[i][j] != -1)
        {
            return mem[i][j];
        }

        if (s[i] == s[j])
        {
            return mem[i][j] = solve(s, i + 1, j - 1);
        }
        return mem[i][j] = 0;
    }

    string longestPalindrome(string s)
    {
        int sz = 0;
        int indx = 0;
        memset(mem, -1, sizeof(mem));
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (solve(s, i, j))
                {
                    if (j - i + 1 > sz)
                    {
                        sz = j - i + 1;
                        indx = i;
                    }
                }
            }
        }
        return s.substr(indx, sz);
    }
};