//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minimumCostPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while (!pq.empty())
        {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == n - 1 && y == n - 1)
                return dist[x][y];

            for (auto d : dir)
            {

                int xx = x + d.first, yy = y + d.second;

                if (xx >= 0 && xx < n && yy >= 0 && yy < n)
                {
                    int newCost = dist[x][y] + grid[xx][yy];

                    if (newCost < dist[xx][yy])
                    {
                        dist[xx][yy] = newCost;
                        pq.push({newCost, {xx, yy}});
                    }
                }
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.minimumCostPath(grid);
        cout << ans << "\n";

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends