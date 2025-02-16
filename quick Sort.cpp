class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int partitionIndex = partition(arr, low, high);
            quickSort(arr, low, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, high);
        }
    }

public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low];
        int l = low + 1;
        int r = high;
        while (l <= r)
        {
            while (l <= r && arr[l] <= pivot)
            {
                l++;
            }
            while (l <= r && arr[r] > pivot)
            {
                r--;
            }
            if (l <= r)
            {
                swap(arr[l], arr[r]);
            }
        }
        swap(arr[low], arr[r]);
        return r;
    }
};