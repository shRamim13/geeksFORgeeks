class Solution
{
public:
    vector<string> ans;
    void solve(string &s, int indx, vector<string> v)
    {
        if (v.size() == 4 && indx == s.size())
        {
            ans.push_back(v[0] + "." + v[1] + "." + v[2] + "." + v[3]);
            return;
        }
        if (v.size() > 4)
        {
            return;
        }
        for (int sz = 1; sz <= 3; sz++)
        {
            if (indx + sz > s.size())
            {
                break;
            }
            string tmp = s.substr(indx, sz);
            int val = stoi(tmp);
            if ((tmp.size() > 1 && tmp[0] == '0') || val > 255)
            {
                continue;
            }
            v.push_back(tmp);
            solve(s, indx + sz, v);
            v.pop_back();
        }
    }

    vector<string> generateIp(string s)
    {
        if (s.size() < 4 || s.size() > 12)
        {
            return {};
        }
        vector<string> v;
        solve(s, 0, v);
        return ans;
    }
};