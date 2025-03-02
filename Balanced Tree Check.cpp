class Solution
{
public:
    int solve(Node *root, int &dif)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lt = solve(root->left, dif);
        int rt = solve(root->right, dif);
        dif = max(dif, abs(lt - rt));
        return 1 + max(lt, rt);
    }
    bool isBalanced(Node *root)
    {
        int dif = 0;
        solve(root, dif);
        return dif <= 1;
    }
};