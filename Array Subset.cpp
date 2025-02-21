//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b)
    {

        unordered_map<int, int> mp;
        for (int x : a)
        {
            mp[x]++;
        }

        for (auto x : b)
        {
            if (mp[x] == 0)
            {
                return false;
            }
            mp[x]--;
        }
        return true;
        // sort(a.begin(), a.end());
        // sort(b.begin(), b.end());
        // int i = 0, j = 0;
        // int n = a.size(), m = b.size();

        // while (i < n && j < m) {
        //     if (a[i] < b[j]) {
        //         i++;
        //     } else if (a[i] == b[j]) {
        //         i++, j++;
        //     } else {
        //         return false;
        //     }
        // }

        // return j == m;
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
        vector<int> a1, a2;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            a1.push_back(number);
        }
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number)
        {
            a2.push_back(number);
        }
        Solution s;
        bool ans = s.isSubset(a1, a2);
        if (ans)
        {
            cout << "true"
                 << "\n";
        }
        else
        {
            cout << "false"
                 << "\n";
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends