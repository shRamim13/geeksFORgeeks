/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    void solve(TreeNode *root, int &cnt, int mx)
    {
        if (root == nullptr)
            return;

        if (root->val >= mx)
        {
            cnt++;
            mx = root->val;
        }

        solve(root->left, cnt, mx);
        solve(root->right, cnt, mx);
    }

    int goodNodes(TreeNode *root)
    {
        int cnt = 0;
        solve(root, cnt, root->val);
        return cnt;
    }
};
