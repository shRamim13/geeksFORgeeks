class Solution
{
public:
    string FirstNonRepeating(string &s)
    {
        unordered_map<char, int> mp;
        queue<int> q;
        string ans = "";
        for (auto x : s)
        {
            q.push(x);
            mp[x]++;
            while (!q.empty() && mp[q.front()] > 1)
            {
                q.pop();
            }
            if (!q.empty())
            {
                ans += q.front();
            }
            else
            {
                ans += '#';
            }
        }
        return ans;
    }
};