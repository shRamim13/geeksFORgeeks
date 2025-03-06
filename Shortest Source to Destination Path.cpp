//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        if (A[0][0] == 0 || A[X][Y] == 0)
        {
            return -1;
        }
        vector<vector<int>> dis(N, vector<int>(M, -1));
        vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        A[0][0] = 0;
        dis[0][0] = 0;
        while (!q.empty())
        {
            auto cpl = q.front();
            q.pop();
            int x = cpl.first;
            int y = cpl.second;
            if (x == X && y == Y)
            {
                return dis[x][y];
            }
            for (auto s : dir)
            {
                int xx = x + s.first;
                int yy = y + s.second;
                if (xx >= 0 && xx < N && yy >= 0 && yy < M && A[xx][yy] == 1)
                {
                    dis[xx][yy] = dis[x][y] + 1;
                    A[xx][yy] = 0;
                    q.push({xx, yy});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";

        cout << "~" << "\n";
    }
}
// } Driver Code Ends