class Solution
{
public:
    int search(vector<int> &arr, int key)
    {
        int i = 0;
        int j = arr.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }
            // // Handle duplicates: skip the duplicates at the start or end
            // if (arr[i] == arr[mid] && arr[mid] == arr[j]) {
            //     i++;
            //     j--;
            // }
            else if (arr[i] <= arr[mid])
            {
                if (arr[i] <= key && key < arr[mid])
                {
                    j = mid - 1;
                }
                else
                {
                    i = mid + 1;
                }
            }
            else
            {
                if (arr[mid] < key && key <= arr[j])
                {
                    i = mid + 1;
                }
                else
                {
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
};