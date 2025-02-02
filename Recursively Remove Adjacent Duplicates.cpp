class Solution
{
public:
    string removeUtil(string &s)
    {
        int sz = s.size();
        string str = "";
        for (int i = 0; i < sz; i++)
        {
            if (i < sz - 1 && s[i] == s[i + 1])
            {
                i++;
                while (i < sz - 1 && s[i] == s[i + 1])
                {
                    i++;
                }
            }
            else
            {
                str += s[i];
            }
        }
        if (sz != str.size())
        {
            str = removeUtil(str);
        }
        return str;
    }
};