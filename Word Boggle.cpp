//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    bool solve(vector<vector<char>> &board, vector<vector<int>> &vis, string &s, int i, int j, int indx, int m, int n)
    {
        if (indx == s.size())
        {
            return true;
        }
        for (auto x : dir)
        {
            int xx = i + x.first;
            int yy = j + x.second;
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && board[xx][yy] == s[indx] && vis[xx][yy] == 0)
            {
                vis[xx][yy] = 1;
                if (solve(board, vis, s, xx, yy, indx + 1, m, n))
                {
                    return true;
                }
                vis[xx][yy] = 0;
            }
        }
        return false;
    }
    bool isExist(vector<vector<char>> &board, string &s)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == s[0])
                {
                    vis[i][j] = 1;
                    if (solve(board, vis, s, i, j, 1, m, n))
                    {
                        return true;
                    }
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
    vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
    {
        vector<string> ans;
        for (string x : dictionary)
        {
            if (isExist(board, x))
            {
                ans.push_back(x);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i)
        {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }

        int R, C;
        cin >> R >> C;
        vector<vector<char>> board(R);
        for (int i = 0; i < R; i++)
        {
            board[i].resize(C);
            for (int j = 0; j < C; j++)
                cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else
        {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++)
                cout << output[i] << " ";
        }
        cout << endl;

        cout << "~" << "\n";
    }
}

// } Driver Code Ends