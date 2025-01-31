class Solution
{
public:
    void reverseInGroups(vector<int> &arr, int k)
    {
        int n = arr.size();
        for (int it = 0; it < n; it = it + k)
        {
            int i = it;
            int j = min(it + k - 1, n - 1);

            while (i < j)
            {
                swap(arr[i++], arr[j--]);
            }
        }
    }
};