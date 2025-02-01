class Solution
{
public:
    void solve(string &s, int indx, vector<string> &v)
    {
        if (indx == s.size())
        {
            v.push_back(s);
            return;
        }
        unordered_set<char> st;
        for (int i = indx; i < s.size(); i++)
        {
            if (st.find(s[i]) != st.end())
            {
                continue;
            }
            st.insert(s[i]);
            swap(s[indx], s[i]);
            solve(s, indx + 1, v);
            swap(s[indx], s[i]);
        }
    }
    vector<string> findPermutation(string &s)
    {
        vector<string> v;
        sort(s.begin(), s.end());
        solve(s, 0, v);
        return v;
    }
};