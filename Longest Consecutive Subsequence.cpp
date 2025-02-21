//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int> &arr)
    {
        // unordered_set<int>st(arr.begin(),arr.end());
        // int maxLen=1;
        // for(int x:arr){
        //     if(st.find(x-1)!=st.end()){
        //         int element=x;
        //         int len=1;
        //         while(st.find(element)!=st.end()){
        //             element++;
        //             len++;
        //         }
        //         maxLen=max(maxLen,len);
        //     }
        // }
        // return maxLen;
        if (arr.empty())
            return 0;

        sort(arr.begin(), arr.end());
        int maxLen = 1, currLen = 1;

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == arr[i - 1])
                continue; // Ignore duplicates
            if (arr[i] == arr[i - 1] + 1)
            {
                currLen++;
            }
            else
            {
                maxLen = max(maxLen, currLen);
                currLen = 1;
            }
        }

        return max(maxLen, currLen);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl
             << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends