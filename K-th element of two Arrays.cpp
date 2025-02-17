//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        int m = a.size();
        int n = b.size();

        if (m > n)
        {
            return kthElement(b, a, k); // Ensure binary search is on the smaller array
        }

        int low = max(0, k - n), high = min(k, m);

        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = k - mid1;

            // Handling boundary conditions
            int p1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
            int p2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];

            int p3 = (mid1 == m) ? INT_MAX : a[mid1];
            int p4 = (mid2 == n) ? INT_MAX : b[mid2];

            if (p1 <= p4 && p2 <= p3)
            { // Valid partition found
                return max(p1, p2);
            }
            else if (p1 > p4)
            {
                high = mid1 - 1; // Move left
            }
            else
            {
                low = mid1 + 1; // Move right
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num)
        {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num)
        {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl
             << "~\n";
    }
    return 0;
}
// } Driver Code Ends