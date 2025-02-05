class Solution
{
public:
    int startStation(vector<int> &gas, vector<int> &cost)
    {
        int total = 0;
        int cur = 0;
        int indx = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            int dif = gas[i] - cost[i];
            cur += dif;
            total += dif;
            if (cur < 0)
            {
                indx = i + 1;
                cur = 0;
            }
        }
        return total >= 0 ? indx : -1;
    }
};