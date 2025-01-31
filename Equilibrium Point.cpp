class Solution
{
public:
       int findEquilibrium(vector<int> &arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int indx;
        int prevSum = 0;
        for (indx = 0; indx < arr.size(); indx++)
        {
            if (prevSum == sum - arr[indx] - prevSum)
            {
                return indx;
            }
            prevSum += arr[indx];
        }
        return -1;
    }
};