//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

/*  Function to calculate the longest consecutive ones
 *   N: given input to calculate the longest consecutive ones
 */
class Solution
{
public:
    int maxConsecutiveOnes(int N)
    {
        int maxlen = 0;
        // int cnt=0;
        // for(int i=0;i<32;i++){
        //     if(N&(1<<i)){
        //         cnt++;
        //     }
        //     else{
        //         maxlen=max(maxlen,cnt);
        //         cnt=0;
        //     }
        // }
        while (N)
        {
            N = (N & (N << 1));
            maxlen++;
        }
        return maxlen;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        Solution obj;
        // calling maxConsecutiveOnes() function
        cout << obj.maxConsecutiveOnes(n) << endl;

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends