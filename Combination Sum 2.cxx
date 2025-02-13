//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &arr, vector<int> v, int val, int indx)
    {
        if (val == 0)
        {
            ans.push_back(v);
            return;
        }
        for (int i = indx; i < arr.size(); i++)
        {
            if (i != indx && arr[i] == arr[i - 1])
            {
                continue;
            }
            if (arr[i] > val)
            {
                break;
            }
            v.push_back(arr[i]);
            solve(arr, v, val - arr[i], i + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        vector<int> v;
        solve(arr, v, target, 0);
        return ans;
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
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        vector<vector<int>> ans = ob.uniqueCombinations(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

/