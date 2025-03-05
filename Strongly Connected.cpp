//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Position this line where user code will be pasted.
class Solution
{
public:
    void topoSort(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (auto x : adj[node])
        {
            if (vis[x] == 0)
            {
                topoSort(x, vis, st, adj);
            }
        }
        st.push(node);
    }

    void dfs(int node, vector<int> &check, vector<int> &v, vector<vector<int>> &reverse_Adj)
    {
        check[node] = 1;
        v.push_back(node);
        for (int i : reverse_Adj[node])
        {
            if (check[i] == 0)
            {
                dfs(i, check, v, reverse_Adj);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj)
    {
        stack<int> st;
        int V = adj.size();
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                topoSort(i, vis, st, adj);
            }
        }

        vector<vector<int>> reverse_Adj(V);
        for (int i = 0; i < V; i++)
        {
            for (int x : adj[i])
            {
                reverse_Adj[x].push_back(i);
            }
        }

        vector<vector<int>> ans;
        vector<int> check(V, 0);
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (check[node] == 0)
            {
                vector<int> v;
                dfs(node, check, v, reverse_Adj);
                ans.push_back(v);
            }
        }
        return ans.size();
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends