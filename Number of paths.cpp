//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfPaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*

class Solution {
  public:
    int numberOfPaths(int m, int n) {
        vector<int>dp(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j]=dp[j-1]+dp[j];
            }
        }
        return dp[n-1];
    }
};
*/

/*
int numberOfPaths(int m, int n) {
        if(m==1||n==1){
            return 1;
        }
        return numberOfPaths(m-1,n)+numberOfPaths(m,n-1);
    }
*/