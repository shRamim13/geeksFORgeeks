class Solution
{
public:
    bool areAnagrams(string &s1, string &s2)
    {
        if (s1.size() != s2.size())
        {
            return false;
        }
        unordered_map<char, int> mp;
        for (char x : s1)
        {
            mp[x]++;
        }
        for (auto x : s2)
        {
            if (mp[x] == 0)
            {
                return false;
            }
            --mp[x];
        }
        return true;
    }
};