//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int activitySelection(vector<int> &start, vector<int> &end)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < end.size(); i++)
        {
            v.push_back({end[i], start[i]});
        }

        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first < b.first; });
        int val = v[0].first;
        int cnt = 1;
        for (int i = 1; i < v.size(); i++)
        {
            int st = v[i].second;
            int et = v[i].first;
            if (st > val)
            {
                cnt++;
                val = et;
            }
        }
        return cnt;
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> end;
        ss.str(input);
        while (ss >> num)
            end.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, end) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends