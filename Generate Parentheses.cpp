// Return list of all combinations of balanced parantheses
class Solution
{
public:
    vector<string> ans;
    void solve(int n, int indx, string s, int pos, int neg)
    {
        if (indx == 2 * n)
        {
            ans.push_back(s);
            return;
        }
        if (pos < n)
        {
            solve(n, indx + 1, s + "(", pos + 1, neg);
        }
        if (neg < pos)
        {
            solve(n, indx + 1, s + ")", pos, neg + 1);
        }
    }
    vector<string> AllParenthesis(int n)
    {
        int indx = 0, pos = 0, neg = 0;
        string s = "";
        solve(n, indx, s, pos, neg);
        return ans;
    }
};