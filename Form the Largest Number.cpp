class Solution
{
public:
    string findLargest(vector<int> &arr)
    {
        vector<string> v;
        string ans = "";
        for (auto x : arr)
        {
            v.push_back(to_string(x));
        }
        sort(v.begin(), v.end(), [](string &a, string &b)
             { return (a + b) > (b + a); });
        if (v[0] == "0")
        {
            return "0";
        }
        for (auto x : v)
        {
            ans += x;
        }
        return ans;
    }
};