class Solution
{
public:
    int arr[501][501];
    int solve(string &s, int i, int j)
    {
        if (i >= j)
        {
            return 0;
        }
        if (arr[i][j] != -1)
        {
            return arr[i][j];
        }
        if (s[i] == s[j])
        {
            return arr[i][j] = solve(s, i + 1, j - 1);
        }
        return arr[i][j] = 1 + min(solve(s, i + 1, j), solve(s, i, j - 1));
    }
    int countMin(string str)
    {
        memset(arr, -1, sizeof(arr));
        return solve(str, 0, str.size() - 1);
    }
};