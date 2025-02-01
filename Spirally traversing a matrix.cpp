class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        int lt = 0, rt = mat[0].size() - 1;
        int up = 0, down = mat.size() - 1;
        vector<int> v;

        while (lt <= rt && up <= down)
        {
            for (int i = lt; i <= rt; i++)
            {
                v.push_back(mat[up][i]);
            }
            up++;

            for (int i = up; i <= down; i++)
            {
                v.push_back(mat[i][rt]);
            }
            rt--;

            if (up <= down)
            {
                for (int i = rt; i >= lt; i--)
                {
                    v.push_back(mat[down][i]);
                }
                down--;
            }

            if (lt <= rt)
            {
                for (int i = down; i >= up; i--)
                {
                    v.push_back(mat[i][lt]);
                }
                lt++;
            }
        }
        return v;
    }
};