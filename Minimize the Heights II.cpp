//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        if (arr.size() <= 1)
        {
            return 0;
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int maxi = arr[n - 1];
        int mini = arr[0];
        int dif = maxi - mini;

        for (int i = 0; i < n - 1; i++)
        {
            mini = min(arr[0] + k, arr[i + 1] - k);
            maxi = max(arr[i] + k, arr[n - 1] - k);
            if (mini < 0)
            {
                continue;
            }
            dif = min(dif, maxi - mini);
        }
        return dif;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
        cout << '~' << endl;
    }
    return 0;
}
// } Driver Code Ends