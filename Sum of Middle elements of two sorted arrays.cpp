//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// Position this line where user code will be pasted.
class Solution
{
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
    {
        int m = arr1.size();
        int n = arr2.size();
        if (m > n)
        {
            return SumofMiddleElements(arr2, arr1);
        }
        int low = 0;
        int high = m;
        while (low <= high)
        {
            int pl1 = (low + high) / 2;
            int pl2 = (m + n + 1) / 2 - pl1;

            int p1 = (pl1 == 0) ? INT_MIN : arr1[pl1 - 1];
            int p2 = (pl2 == 0) ? INT_MIN : arr2[pl2 - 1];

            int p3 = (pl1 == m) ? INT_MAX : arr1[pl1];
            int p4 = (pl2 == n) ? INT_MAX : arr2[pl2];

            if (p1 <= p4 && p2 <= p3)
            {
                return max(p1, p2) + min(p3, p4);
            }
            else if (p1 > p4)
            {
                high = pl1 - 1;
            }
            else
            {
                low = pl1 + 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
// Back-end complete function template in C++

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1)
        {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2)
        {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl
             << "~\n";
    }
}
// } Driver Code Ends