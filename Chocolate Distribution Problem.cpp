class Solution
{
public:
    int findMinDiff(vector<int> &a, int m)
    {
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        for (int i = 0; i < a.size() - m + 1; i++)
        {
            ans = min(ans, (a[i + m - 1] - a[i]));
        }
        return ans;
    }
};