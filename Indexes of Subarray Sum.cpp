class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        int i = 0;
        int j = 0;
        int n = arr.size();
        int sum = 0;
        vector<int> v;
        while (j < n)
        {
            sum += arr[j];
            while (target < sum && i < j)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == target)
            {
                v.push_back(i + 1);
                v.push_back(j + 1);
                return v;
            }
            j++;
        }
        if (v.empty())
        {
            v.push_back(-1);
        }
        return v;
    }
};