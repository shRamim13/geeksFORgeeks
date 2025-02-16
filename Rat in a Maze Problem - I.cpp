class Solution
{
public:
    vector<string> ans;
    vector<pair<char, pair<int, int>>> dir = {{'D', {1, 0}}, {'U', {-1, 0}}, {'R', {0, 1}}, {'L', {0, -1}}};

    void solve(vector<vector<int>> &mat, int row, int col, string s)
    {

        int n = mat.size();
        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(s);
            return;
        }
        mat[row][col] = 0;

        for (auto x : dir)
        {
            int xx = x.second.first + row;
            int yy = x.second.second + col;
            char ch = x.first;
            if (xx >= 0 && xx < n && yy >= 0 && yy < n && mat[xx][yy] == 1)
            {
                solve(mat, xx, yy, s + ch);
            }
        }
        mat[row][col] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        // vector<vector<int>>vis(n,vector<int>(n,0));
        solve(mat, 0, 0, "");
        return ans;
    }
};