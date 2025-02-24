class Solution
{
public:
    // Function to sort an array using Heap Sort.
    void heapify(vector<int> &arr, int n, int i)
    {
        int lt = (2 * i) + 1;
        int rt = (2 * i) + 2;
        int largest = i;
        if (lt < n && arr[largest] < arr[lt])
        {
            largest = lt;
        }
        if (rt < n && arr[largest] < arr[rt])
        {
            largest = rt;
        }
        if (i != largest)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    void build_Heap(vector<int> &arr, int n)
    { /// max heap
        for (int i = (n - 2) / 2; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }
    void heapSort(vector<int> &arr)
    {
        int n = arr.size();
        build_Heap(arr, n);
        for (int i = n - 1; i >= 1; i--)
        {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }
};