//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool solve(int node, int parent, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1;
        for (int x : adj[node])
        {
            if (vis[x] == 0)
            {
                if (solve(x, node, adj, vis))
                {
                    return true;
                }
            }
            else if (x != parent)
            {
                return true;
            }
        }
        return false;
    }
    // bool solve(int node,int parent,vector<vector<int>>&adj,vector<int>&vis){
    //     queue<pair<int,int>>q;
    //     q.push({node,parent});
    //     vis[node]=1;
    //     while(!q.empty()){
    //         auto x=q.front();
    //         q.pop();
    //         int nd=x.first;
    //         int par=x.second;
    //         for(int i:adj[nd]){
    //             if(vis[i]==0){
    //                 vis[i]=1;
    //                 q.push({i,nd});
    //             }else if(i!=par){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool isCycle(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                if (solve(i, -1, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends