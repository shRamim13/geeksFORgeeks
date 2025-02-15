//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isSafe(vector<vector<int>> &mat, int row, int col, int num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (mat[i][col] == num)
            {
                return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (mat[row][i] == num)
            {
                return false;
            }
        }

        int r = row / 3 * 3;
        int c = col / 3 * 3;

        for (int i = 0; i < 9; i++)
        {
            if (mat[r + i / 3][c + i % 3] == num)
            {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<int>> &mat)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (mat[i][j] == 0)
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (isSafe(mat, i, j, k))
                        {
                            mat[i][j] = k;
                            if (solve(mat))
                            {
                                return true;
                            }
                            mat[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat)
    {
        solve(mat);
    }
};

//{ Driver Code Starts.

vector<int> inputLine()
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num)
    {
        res.push_back(num);
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++)
        {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid)
        {
            for (auto elem : v)
            {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
