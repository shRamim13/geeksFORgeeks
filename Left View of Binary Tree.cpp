class Solution
{
public:
    void solve(Node *root, vector<int> &v, int cnt)
    {
        if (root == nullptr)
        {
            return;
        }
        if (v.size() == cnt)
        {
            v.push_back(root->data);
        }
        cnt++;
        solve(root->left, v, cnt);
        solve(root->right, v, cnt);
    }
    vector<int> leftView(Node *root)
    {
        vector<int> v;
        solve(root, v, 0);
        return v;
    }
};