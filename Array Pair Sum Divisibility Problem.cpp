//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool canPair(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        for (int x : arr)
        {
            int r = (x % k);
            if (x < 0)
            {
                x += k;
            }
            mp[r]++;
        }
        for (int i = 0; i < k; i++)
        {
            if (i == 0)
            {
                if (mp[i] % 2)
                {
                    return false;
                }
            }
            else
            {
                if (mp[i] != mp[k - i])
                {
                    return false;
                }
            }
        }
        return true;
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
        {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        bool ans = obj.canPair(arr, k);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends