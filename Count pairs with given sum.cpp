//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        unordered_map<int, int> mp;
        int cnt = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            int pair = target - arr[i];
            if (mp.find(pair) != mp.end())
            {
                cnt += mp[pair];
            }
            mp[arr[i]]++;
        }
        return cnt;
        // for(int i=0;i<arr.size();i++){
        //     mp[arr[i]]++;
        // }
        // for(int i=0;i<arr.size();i++){

        //     if(mp.find(target-arr[i])!=mp.end()){
        //         cnt+=mp[target-arr[i]];
        //     }
        //     if(arr[i]==target-arr[i]){
        //         cnt--;
        //     }
        // }
        // return cnt/2;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl
             << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends