#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void mergeArrays(vector<int> &a, vector<int> &b)
    {
        int m = a.size();
        int n = b.size();
        int i = m - 1; // Correct the index to m-1
        int j = 0;

        while (i >= 0 && j < n && a[i] > b[j])
        {
            swap(a[i--], b[j++]);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<int> a = {1, 4, 7, 8, 10};
    vector<int> b = {2, 3, 9};

    sol.mergeArrays(a, b);

    // Print modified arrays
    for (int num : a)
        cout << num << " ";
    cout << endl;

    for (int num : b)
        cout << num << " ";
    cout << endl;

    return 0;
}
