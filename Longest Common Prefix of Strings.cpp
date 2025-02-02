class Solution
{
public:
    string longestCommonPrefix(vector<string> arr)
    {
        sort(arr.begin(), arr.end());
        int indx = 0;
        for (int i = 0; indx < arr[0].size(); i++)
        {
            if (arr[0][i] != arr[arr.size() - 1][i])
            {
                break;
            }
            indx++;
        }
        return arr[0].substr(0, indx);
    }
};