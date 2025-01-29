class Solution
{
public:
    void rearrange(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int mxIndx = arr.size() - 1;
        int minIndx = 0;
        int maxVal = arr[mxIndx] + 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i % 2 == 0)
            {
                arr[i] = arr[i] + (arr[mxIndx] % maxVal) * maxVal;
                mxIndx--;
            }
            else
            {
                arr[i] = arr[i] + (arr[minIndx] % maxVal) * maxVal;
                minIndx++;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = arr[i] / maxVal;
        }
    }
};