//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, int> pr;
// User Function Template
class Solution
{
public:
    vector<int> solve(vector<vector<pair<int, int>>> &adj, int src)
    {
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        int n = adj.size();
        vector<int> dis(n, INT_MAX);
        pq.push({0, src});
        dis[src] = 0;
        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int node = x.second;
            int route = x.first;
            if (route > dis[node])
            {
                continue;
            }
            for (auto &x : adj[node])
            {
                int nextNode = x.first;
                int nodeVal = x.second;
                int totalDis = nodeVal + route;
                if (totalDis < dis[nextNode])
                {
                    dis[nextNode] = totalDis;
                    pq.push({totalDis, nextNode});
                }
            }
        }
        return dis;
    }
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        return solve(adj, src);
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
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends