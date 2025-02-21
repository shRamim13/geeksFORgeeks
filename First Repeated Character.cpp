//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string firstRepChar(string s)
    {
        unordered_map<char, int> mp;

        string str = "-1";
        for (auto x : s)
        {
            if (mp[x] > 0)
            {
                str = x;
                break;
            }
            mp[x]++;
        }
        return str;
    }
};

//{ Driver Code Starts.
//    Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.firstRepChar(str) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends