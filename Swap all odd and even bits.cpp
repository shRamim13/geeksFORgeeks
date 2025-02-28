//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    // Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
        unsigned int even_bits = n & 0XAAAAAAAA;
        unsigned int odd_bits = n & 0X55555555;
        even_bits = even_bits >> 1;
        odd_bits = odd_bits << 1;
        unsigned int result = even_bits | odd_bits;
        return result;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        unsigned int n;
        cin >> n; // input n

        Solution ob;
        // calling swapBits() method
        cout << ob.swapBits(n) << endl;

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends