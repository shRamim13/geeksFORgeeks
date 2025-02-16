class Solution
{
public:
    int firstOccurrence(vector<int> &arr, int k)
    {
        int i = 0, j = arr.size() - 1, ans = -1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (arr[mid] == k)
            {
                ans = mid; // Store index and keep searching left
                j = mid - 1;
            }
            else if (arr[mid] < k)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return ans;
    }

    int lastOccurrence(vector<int> &arr, int k)
    {
        int i = 0, j = arr.size() - 1, ans = -1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (arr[mid] == k)
            {
                ans = mid; // Store index and keep searching right
                i = mid + 1;
            }
            else if (arr[mid] < k)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return ans;
    }
    int binarysearch(vector<int> &arr, int k)
    {
        return firstOccurrence(arr, k); // lastOccurrence(arr, k);
    }
};