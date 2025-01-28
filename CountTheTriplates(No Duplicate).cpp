class Solution
{
    int solve(vector<int> &arr, int target, int indx)
    {
        int i = 0, j = indx - 1;
        int cnt = 0;

        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum == target)
            {
                cnt++; // Found a valid triplet
                i++;
                j--;

                // Skip duplicates for `i` and `j`
                while (i < j && arr[i] == arr[i - 1])
                    i++;
                while (i < j && arr[j] == arr[j + 1])
                    j--;
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return cnt;
    }

public:
    int countTriplet(vector<int> &arr)
    {
        sort(arr.begin(), arr.end()); // Sort the array for the two-pointer approach
        int ans = 0;

        // Iterate over each element as the target
        for (int i = arr.size() - 1; i >= 2; i--)
        {
            if (i < arr.size() - 1 && arr[i] == arr[i + 1])
                continue; // Skip duplicates for the target
            ans += solve(arr, arr[i], i);
        }

        return ans;
    }
};
