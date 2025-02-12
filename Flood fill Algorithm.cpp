//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> vis;
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}}; // 4-directional movement

    void solve(vector<vector<int>> &image, int i, int j, int col, int newCol)
    {
        vis[i][j] = 1;
        image[i][j] = newCol;

        for (auto dirPair : dir)
        { // Change from 'auto &[x, y]' to 'auto dirPair'
            int x = dirPair.first;
            int y = dirPair.second;
            int xx = i + x;
            int yy = j + y;
            if (xx >= 0 && xx < image.size() && yy >= 0 && yy < image[0].size() && !vis[xx][yy] && image[xx][yy] == col)
            {
                solve(image, xx, yy, col, newCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int col = image[sr][sc];
        if (col == newColor)
            return image; // Prevent infinite recursion if the color is the same

        vis.assign(image.size(), vector<int>(image[0].size(), 0)); // Initialize visited matrix
        solve(image, sr, sc, col, newColor);
        return image;
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
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends