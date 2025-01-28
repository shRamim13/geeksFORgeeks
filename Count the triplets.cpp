class Solution
{

    int solve(vector<int> &arr, int target, int indx)
    {
        int i = 0, j = indx - 1;
        int cnt = 0;

        while (i < j)
        {
            int sum = arr[i] + arr[j]; // Calculate the sum of two elements
            if (sum == target)
            {
                cnt++; // Found a valid pair
                i++;
                j--;
            }
            else if (sum < target)
            {
                i++; // Move the left pointer to increase the sum
            }
            else
            {
                j--; // Move the right pointer to decrease the sum
            }
        }

        return cnt;
    }

public:
    int countTriplet(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            ans += solve(arr, arr[i], i);
        }
        return ans;
    }
};