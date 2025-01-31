class Solution
{
public:
    void rearrange(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int maxi = arr[n - 1] + 1;
        int lowIndx = 0;
        int highIndx = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                arr[i] = arr[i] + (arr[highIndx] % maxi) * maxi;
                highIndx--;
            }
            else
            {
                arr[i] = arr[i] + (arr[lowIndx] % maxi) * maxi;
                lowIndx++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] / maxi;
        }
    }
};