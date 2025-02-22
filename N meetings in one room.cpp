//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int> &start, vector<int> &end)
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
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num)
        {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num)
        {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends