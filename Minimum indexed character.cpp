//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find the minimum indexed character.
    int minIndexChar(string &s1, string &s2)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s2.size(); i++)
        {
            if (mp.find(s2[i]) == mp.end())
            {
                mp[s2[i]] = i;
            }
        }
        for (int i = 0; i < s1.size(); i++)
        {
            if (mp.find(s1[i]) != mp.end())
            {
                return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        string patt;
        cin >> str;
        cin >> patt;
        Solution obj;
        cout << obj.minIndexChar(str, patt) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends