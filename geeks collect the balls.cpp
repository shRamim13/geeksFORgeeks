Geek collects the balls //{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
    using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxBalls(int n, int m, vector<int> a, vector<int> b)
    {
        int sumA = 0, sumB = 0;
        int i = 0, j = 0;
        int maxBall = 0;
        while (i < n && j < m)
        {
            while (i + 1 < n && a[i] == a[i + 1])
            {
                sumA += a[i];
                i++;
            }
            while (j + 1 < m && b[j] == b[j + 1])
            {
                sumB += b[j];
                j++;
            }
            if (a[i] == b[j])
            {
                maxBall += max(sumA, sumB) + a[i];
                i++, j++;
                sumA = 0, sumB = 0;
            }
            else if (a[i] < b[j])
            {
                sumA += a[i];
                i++;
            }
            else
            {
                sumB += b[j];
                j++;
            }
        }
        while (i < n)
        {
            sumA += a[i];
            i++;
        }

        while (j < m)
        {
            sumB += b[j];
            j++;
        }
        maxBall += max(sumA, sumB);
        return maxBall;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        vector<int> a(N), b(M);
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.maxBalls(N, M, a, b) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends