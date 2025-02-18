class Solution
{
public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]

    // Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
    {
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int x : A1)
        {
            mp[x]++;
        }
        for (int x : A2)
        {
            int val = mp[x];
            while (val--)
            {
                ans.push_back(x);
            }
            mp.erase(x);
        }
        vector<int> v;
        for (int x : A1)
        {
            if (mp[x])
            {
                v.push_back(x);
            }
        }
        sort(v.begin(), v.end());
        for (auto x : v)
        {
            ans.push_back(x);
        }
        return ans;
    }
};