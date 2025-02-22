//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s1, string &s2)
    {
        int m = s1.size();
        int n = s2.size();
        if (m < n)
        {
            return "";
        }
        unordered_map<char, int> mp;
        for (auto x : s2)
        {
            mp[x]++;
        }
        int i = 0;
        int j = 0;
        int minLen = INT_MAX;
        int indx = 0;
        while (j < m)
        {
            char ch = s1[j];
            if (mp[ch] > 0)
            {
                n--;
            }
            mp[ch]--;
            while (n == 0)
            {
                int len = j - i + 1;
                if (len < minLen)
                {
                    minLen = len;
                    indx = i;
                }
                mp[s1[i]]++;
                if (mp[s1[i]] > 0)
                {
                    n++;
                }
                i++;
            }
            j++;
        }
        return (minLen == INT_MAX) ? "" : s1.substr(indx, minLen);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        string str = obj.smallestWindow(s1, s2);
        if (str.size() == 0)
        {
            cout << "\"\"" << endl;
        }
        else
        {
            cout << str << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends