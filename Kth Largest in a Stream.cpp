Kth Largest in a Stream //{ Driver Code Starts
#include <bits/stdc++.h>
    using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> kthLargest(int k, int arr[], int n)
    {
        vector<int> result;
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);

            if (pq.size() > k)
            {
                pq.pop();
            }

            if (pq.size() < k)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(pq.top());
            }
        }

        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k, arr, n);
        for (int i : v)
            cout << i << " ";
        cout << endl;

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends