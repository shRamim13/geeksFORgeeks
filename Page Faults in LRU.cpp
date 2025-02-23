//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int pageFaults(int N, int C, int pages[])
    {
        unordered_set<int> st;
        queue<int> q;
        int pgf = 0;
        for (int i = 0; i < N; i++)
        {
            int pg = pages[i];

            if (st.find(pages[i]) == st.end())
            {
                pgf++;
                if (st.size() == C)
                {
                    int val = q.front();
                    q.pop();
                    st.erase(val);
                }
                st.insert(pages[i]);
                q.push(pages[i]);
            }
            else
            {
                queue<int> q1;
                while (!q.empty())
                {
                    int val = q.front();
                    q.pop();
                    if (pg != val)
                    {
                        q1.push(val);
                    }
                }
                q1.push(pg);
                swap(q, q1);
            }
        }
        return pgf;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, C;
        cin >> N;
        int pages[N];
        for (int i = 0; i < N; i++)
            cin >> pages[i];
        cin >> C;

        Solution ob;
        cout << ob.pageFaults(N, C, pages) << "\n";

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends