//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<int> vis(V, 0);
        vector<int> parent(V, -1); // Stores the parent of each node in MST

        pq.push(make_tuple(0, 0, -1)); // {weight, node, parent}
        int sum = 0;

        while (!pq.empty())
        {
            auto [weight, node, par] = pq.top();
            pq.pop();

            if (vis[node])
                continue;

            vis[node] = 1;
            sum += weight;
            parent[node] = par; // Store the parent of the node

            for (auto &x : adj[node])
            {
                int next = x[0];
                int cost = x[1];

                if (!vis[next])
                {
                    pq.push(make_tuple(cost, next, node));
                }
            }
        }

        return sum;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends