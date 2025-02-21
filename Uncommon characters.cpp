//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string uncommonChars(string &s1, string &s2)
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for (char x : s1)
        {
            v1[x - 'a'] = 1;
        }
        for (char x : s2)
        {
            v2[x - 'a'] = 1;
        }
        string s = "";
        for (int i = 0; i < 26; i++)
        {
            if (v1[i] ^ v2[i])
            {
                s += ('a' + i);
            }
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A;
        cin >> B;
        Solution ob;
        cout << ob.uncommonChars(A, B);
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends