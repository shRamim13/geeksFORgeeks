class Solution
{
public:
    bool isTree(int n, int m, vector<vector<int>> &edges)
    {
        if (m != n - 1)
            return 0; // Condition 1: A tree must have exactly n-1 edges

        vector<vector<int>> adj(n);

        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> q;

        // Start BFS from node 0
        q.push(0);
        visited[0] = true;
        int visitedCount = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            visitedCount++;

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return visitedCount == n;
    }
};