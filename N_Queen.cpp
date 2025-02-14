class Solution
{
public:
    vector<vector<string>> ans; // Stores all valid board configurations

    // Function to check if placing a queen at (row, col) is safe
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return false; // Same column
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false; // Upper-left diagonal
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false; // Upper-right diagonal
        }
        return true;
    }

    // Recursive function to solve N-Queens
    void solve(vector<string> &board, int row, int n)
    {
        if (row == n)
        {
            ans.push_back(board); // Store valid board configuration
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isSafe(board, row, col, n))
            {
                board[row][col] = 'Q'; // Place queen
                solve(board, row + 1, n);
                board[row][col] = '.'; // Backtrack
            }
        }
    }

    // Function to return all valid board configurations
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.')); // Initialize empty board
        solve(board, 0, n);
        return ans;
    }
};
