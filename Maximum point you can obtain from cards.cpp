//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int l_s = 0, r_s = 0, maxSum = 0;
        for (int i = 0; i < k; i++)
        {
            l_s += cardPoints[i];
        }
        maxSum = l_s;
        int r_indx = cardPoints.size() - 1;
        for (int i = k - 1; i >= 0; i--)
        {
            l_s -= cardPoints[i];
            r_s += cardPoints[r_indx];
            r_indx--;
            maxSum = max(maxSum, l_s + r_s);
        }
        return maxSum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // Consume the newline character

    while (t--)
    {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> cardPoints;
        while (ss >> num)
            cardPoints.push_back(num);

        int k;
        cin >> k;
        cin.ignore(); // Consume the newline character

        Solution ob;
        cout << ob.maxScore(cardPoints, k) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends