//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // target : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> v;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && arr[j] == arr[j - 1])
                {
                    continue;
                }
                int l = j + 1;
                int r = n - 1;
                while (l < r)
                {
                    int sum = arr[i] + arr[j] + arr[l] + arr[r];
                    if (sum == target)
                    {
                        v.push_back({arr[i], arr[j], arr[l], arr[r]});
                        while (l < r && arr[l] == arr[l + 1])
                        {
                            l++;
                        }
                        while (l < r && arr[r] == arr[r - 1])
                        {
                            r--;
                        }
                        l++;
                        r--;
                    }
                    else if (sum < target)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--)
    {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(arr, d);
        sort(ans.begin(), ans.end());
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << endl;
        }
        if (ans.empty())
        {
            cout << -1 << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends