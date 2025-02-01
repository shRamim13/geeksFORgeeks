class Solution
{
public:
    int findElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> lftMax(n, 0);
        vector<int> rgtMin(n, 0);
        lftMax[0] = arr[0];
        rgtMin[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++)
        {
            lftMax[i] = max(lftMax[i - 1], arr[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            rgtMin[i] = min(rgtMin[i + 1], arr[i]);
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (lftMax[i] <= arr[i] && arr[i] <= rgtMin[i])
            {
                return arr[i];
            }
        }
        return -1;
    }
};