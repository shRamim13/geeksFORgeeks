//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution
{
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b)
    {
        unordered_map<int, int> mp;
        for (auto x : a)
        {
            mp[x]++;
        }
        vector<int> v;
        for (auto x : b)
        {
            if (mp[x] > 0)
            {
                v.push_back(x);
                mp[x]--;
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0)
    {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> a;
        int num;
        while (ss >> num)
        {
            a.push_back(num);
        }
        string str1;
        getline(cin, str1);

        stringstream ss1(str1);
        vector<int> b;
        int num1;
        while (ss1 >> num1)
        {
            b.push_back(num1);
        }
        Solution ob;
        vector<int> result;
        result = ob.commonElements(a, b);
        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends