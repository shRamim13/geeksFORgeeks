//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies + N);
        int i = 0;
        int j = N - 1;
        int minCost = 0;
        while (i <= j)
        {
            minCost += candies[i];
            if (i <= j)
            {
                j = j - K;
            }
            i++;
        }

        i = 0, j = N - 1;
        int maxCost = 0;
        while (i <= j)
        {
            maxCost += candies[j];
            if (i <= j)
            {
                i = i + K;
            }
            j--;
        }
        vector<int> v;
        v.push_back(minCost);
        v.push_back(maxCost);
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends