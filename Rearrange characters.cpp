//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends

class Solution
{
public:
    string rearrangeString(string s)
    {
        priority_queue<pair<int, char>> pq;
        vector<int> v(26, 0);
        for (auto x : s)
        {
            v[x - 'a']++;
        }
        for (int x = 0; x < 26; x++)
        {
            if (v[x] > 0)
            {
                pq.push({v[x], (x + 'a')});
            }
        }
        string str = "";
        queue<pair<int, char>> q;
        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int cnt = x.first;
            char ch = x.second;
            str += ch;
            cnt--;
            q.push({cnt, ch});
            if (q.size() >= 2)
            {
                auto y = q.front();
                q.pop();
                if (y.first > 0)
                {
                    pq.push({y.first, y.second});
                }
            }
        }
        return (str.size() == s.size()) ? str : "";
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
        cin >> str;
        Solution ob;
        string str1 = ob.rearrangeString(str);
        int flag = 1;
        int c[26] = {0};
        for (int i = 0; i < str.length(); i++)
            c[str[i] - 'a'] += 1;
        int f = 0;
        int x = (str.length() + 1) / 2;
        for (int i = 0; i < 26; i++)
        {
            if (c[i] > x)
                f = 1;
        }
        if (f)
        {
            if (str1 == "")
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else
        {
            int a[26] = {0};
            int b[26] = {0};
            for (int i = 0; i < str.length(); i++)
                a[str[i] - 'a'] += 1;
            for (int i = 0; i < str1.length(); i++)
                b[str1[i] - 'a'] += 1;

            for (int i = 0; i < 26; i++)
                if (a[i] != b[i])
                    flag = 0;

            for (int i = 0; i < str1.length(); i++)
            {
                if (i > 0)
                    if (str1[i - 1] == str1[i])
                        flag = 0;
            }
            if (flag == 1)
                cout << "1\n";
            else
                cout << "0\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends