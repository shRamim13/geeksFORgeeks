class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(vector<int> &arr)
    {
        vector<int> v;
        v.push_back(arr[arr.size() - 1]);
        int maxi = arr[arr.size() - 1];
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            if (maxi <= arr[i])
            {
                maxi = arr[i];
                v.push_back(arr[i]);
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};