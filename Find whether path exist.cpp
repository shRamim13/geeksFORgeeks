//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                    grid[i][j] = 0;
                    break;
                }
            }
        }
        while (!q.empty())
        {
            auto s = q.front();
            q.pop();
            int x = s.first;
            int y = s.second;
            if (grid[x][y] == 2)
            {
                return true;
            }
            for (auto v : dir)
            {
                int xx = x + v.first;
                int yy = y + v.second;
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && grid[xx][yy] != 0)
                {
                    q.push({xx, yy});
                    vis[xx][yy] = 1;
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
        bool ans = obj.is_Possible(grid);
        cout << ((ans) ? "1\n" : "0\n");

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends