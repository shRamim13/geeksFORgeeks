class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int stationCount = 0;
        int n = arr.size();
        int i = 0, j = 0;
        int maxi = 0;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                stationCount++;
                maxi = max(maxi, stationCount);
                i++;
            }
            else
            {
                stationCount--;
                maxi = max(maxi, stationCount);
                j++;
            }
        }
        return maxi;
    }
};
