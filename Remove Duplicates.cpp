class Solution
{
public:
    string removeDups(string &s)
    {
        string ans = "";
        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            if (!v[s[i] - 'a'])
            {
                ans += s[i];
                v[s[i] - 'a']++;
            }
        }
        return ans;
    }
};