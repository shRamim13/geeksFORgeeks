//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        int c0 = 0, c1 = 0, c2 = 0;
        for (auto x : arr)
        {
            if (x == 0)
                c0++;
            else if (x == 1)
                c1++;
            else
                c2++;
        }
        int k = 0;
        for (; k < c0; k++)
            arr[k] = 0;
        for (; k < c0 + c1; k++)
            arr[k] = 1;
        for (; k < c0 + c1 + c2; k++)
            arr[k] = 2;
    }
};