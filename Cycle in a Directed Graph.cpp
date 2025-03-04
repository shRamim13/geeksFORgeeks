class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int x : adj[i])
            {
                indeg[x]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (int i : adj[node])
            {
                indeg[i]--;
                if (indeg[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return cnt != n;
    }
};

/*
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool solve(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&reqstk){
        vis[node]=1;
        reqstk[node]=1;
        for(int i:adj[node]){
            if(vis[i]==0){
                if(solve(i,adj,vis,reqstk)){
                    return true;
                }
            }
            else if(reqstk[i]==1){
                    return true;
            }
        }
        reqstk[node]=0;
        return false;
    }
    bool isCyclic(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int>reqstk(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(solve(i,adj,vis,reqstk)){
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends

*/