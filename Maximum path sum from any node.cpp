class Solution
{
public:
    int maxSum;
    int solve(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lt = max(0, solve(root->left));
        int rt = max(0, solve(root->right));
        maxSum = max(maxSum, (root->data + lt + rt));
        return root->data + max(lt, rt);
    }
    int findMaxSum(Node *root)
    {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};