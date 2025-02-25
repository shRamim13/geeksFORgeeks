//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<double> getMedian(vector<int> &arr)
    {
        vector<double> v;
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int>> pq1;
        for (int x : arr)
        {
            if (pq.empty() || x <= pq.top())
            {
                pq.push(x);
            }
            else
            {
                pq1.push(x);
            }
            if (pq.size() > pq1.size() + 1)
            {
                pq1.push(pq.top());
                pq.pop();
            }
            else if (pq.size() < pq1.size())
            {
                pq.push(pq1.top());
                pq1.pop();
            }

            if (pq.size() == pq1.size())
            {
                v.push_back((pq.top() + pq1.top()) / 2.0);
            }
            else
            {
                v.push_back(pq.top());
            }
        }
        return v;
        // vector<double> medians;
        // priority_queue<int> left;  // Max-heap
        // priority_queue<int, vector<int>, greater<int>> right;  // Min-heap

        // for (int num : arr) {
        //     left.push(num);
        //     right.push(left.top());
        //     left.pop();

        //     // Balance heaps
        //     if (left.size() < right.size()) {
        //         left.push(right.top());
        //         right.pop();
        //     }

        //     // Store median
        //     medians.push_back(left.size() > right.size() ? left.top() : (left.top() + right.top()) / 2.0);
        // }

        // return medians;
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num)
        {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends