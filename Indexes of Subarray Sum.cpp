//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        vector<int> v;
        int i = 0, j = 0;
        int n = arr.size();
        int sum = 0;
        while (j < n)
        {
            sum += arr[j];
            while (sum > target && i < j)
            {
                sum -= arr[i++];
            }
            if (sum == target)
            {
                v.push_back(i + 1);
                v.push_back(j + 1);
                return v;
            }
            j++;
        }
        v.push_back(-1);
        return v;
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
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result)
        {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends