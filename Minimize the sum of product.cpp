//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    typedef long long int ll;

    long long int minValue(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end(), greater<int>());
        long long sum = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            sum += arr1[i] * arr2[i];
        }
        return sum;
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
        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1)
        {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2)
        {
            arr2.push_back(number2);
        }
        Solution ob;
        long long int ans = ob.minValue(arr1, arr2);
        cout << ans << endl
             << "~\n";
    }
    return 0;
}
// } Driver Code Ends