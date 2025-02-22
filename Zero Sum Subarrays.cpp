//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int Count_Subarray_Sum_Equals_K(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        int prefixSum = 0;
        for (int x : arr)
        {
            prefixSum += x;
            if (mp.find(prefixSum - k) != mp.end())
            {
                cnt += mp[prefixSum - k];
            }
            mp[prefixSum]++;
        }
        return cnt;
    }
    int findSubarray(vector<int> &arr)
    {
        int k = 0;
        return Count_Subarray_Sum_Equals_K(arr, k);
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends