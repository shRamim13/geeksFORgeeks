class Solution
{
public:
    void merge(vector<int> &arr, int l, int mid, int r)
    {
        vector<int> v;
        int left = l;
        int right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= r)
        {
            if (arr[left] <= arr[right])
            {
                v.push_back(arr[left]);
                left++;
            }
            else
            {
                v.push_back(arr[right]);
                right++;
            }
        }

        // Copy remaining elements from the left half
        while (left <= mid)
        {
            v.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements from the right half
        while (right <= r)
        {
            v.push_back(arr[right]);
            right++;
        }

        // Copy merged elements back to the original array
        for (int k = 0; k < v.size(); k++)
        {
            arr[l + k] = v[k];
        }
    }
    void mergeSort(vector<int> &arr, int l, int r)
    {
        if (l < r)
        {
            int mid = (l + r) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
};
