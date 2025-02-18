#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr)
{
    // Frequency map
    unordered_map<int, int> mp;
    for (auto x : arr)
    {
        mp[x]++;
    }

    // Create a vector of pairs (element, frequency)
    vector<pair<int, int>> tmp;
    for (auto x : mp)
    {
        int val = x.first;
        int freq = x.second;
        tmp.push_back({val, freq});
        // tmp.push_back(x)
    }

    // Sort by frequency (descending) and by value (ascending) when frequencies are the same
    sort(tmp.begin(), tmp.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
             if (a.second == b.second)
             {
                 return a.first < b.first; // Sort by element value if frequencies are the same
             }
             return a.second > b.second; // Sort by frequency in descending order
         });

    // Reconstruct the result vector based on sorted frequencies
    vector<int> v;
    for (auto x : tmp)
    {
        // v.insert(v.end(), x.second, x.first);  // Insert the element `x.first` `x.second` times
        int value = x.first;
        int freq = x.second;
        while (freq--)
        {
            v.push_back(value);
        }
    }

    // Output the result
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t; // Number of test cases
    while (t--)
    {
        int x;
        cin >> x; // Size of the array
        vector<int> v;
        while (x--)
        {
            int s;
            cin >> s;
            v.push_back(s);
        }
        solve(v);
    }

    return 0;
}
