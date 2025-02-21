//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find all pairs with given sum.
    vector<pair<int, int>> allPairs(int target, vector<int> &arr1, vector<int> &arr2)
    {

        unordered_map<int, int> mp;
        vector<pair<int, int>> v;

        sort(arr1.begin(), arr1.end());

        for (int i = 0; i < arr2.size(); i++)
        {
            mp[arr2[i]]++;
        }

        for (int i = 0; i < arr1.size(); i++)
        {
            int val = target - arr1[i];
            if (mp.count(val) > 0)
            {
                int t = mp[val];
                while (t--)
                {
                    v.push_back({arr1[i], val});
                }
            }
        }

        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr1;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2); // Read the entire line for the array elements
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2)
        {
            arr2.push_back(number2);
        }

        Solution ob;
        vector<pair<int, int>> vp = ob.allPairs(x, arr1, arr2);
        int sz = vp.size();
        if (sz == 0)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < sz; i++)
            {
                if (i == 0)
                    cout << vp[i].first << " " << vp[i].second;
                else
                    cout << ", " << vp[i].first << " " << vp[i].second;
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends