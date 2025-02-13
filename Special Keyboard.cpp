class Solution
{
public:
    long long int optimalKeys(int N)
    {
        if (N <= 6)
        {
            return N;
        }

        vector<long long> dp(N + 1, 0);

        for (int i = 1; i <= 6; i++)
        {
            dp[i] = i;
        }

        for (int i = 7; i <= N; i++)
        {
            for (int j = i - 3; j >= 1; j--)
            {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }

        return dp[N];
    };
};