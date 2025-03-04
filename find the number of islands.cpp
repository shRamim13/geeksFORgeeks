//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<pair<int, int>> dir = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, // Up, Down, Left, Right
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1} // Diagonal directions
    };

    void solve(int i, int j, int m, int n, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        vis[i][j] = 1;
        for (auto s : dir)
        {
            int x = s.first + i;
            int y = s.second + j;
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && vis[x][y] == 0)
            {
                solve(x, y, m, n, vis, grid);
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && vis[i][j] == 0)
                {
                    cnt++;
                    solve(i, j, m, n, vis, grid);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends