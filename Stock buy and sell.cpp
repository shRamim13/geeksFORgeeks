class Solution
{
public:
    int stockBuySell(vector<int> &arr)
    {
        int maxProfit = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] < arr[i])
            {
                maxProfit += (arr[i] - arr[i - 1]);
            }
        }
        return maxProfit;
    }
};