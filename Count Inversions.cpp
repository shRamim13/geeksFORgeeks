class Solution
{
public:
    int cnt = 0;
    void merge(vector<int> &arr, int i, int mid, int j)
    {
        vector<int> v;
        int lft = i;
        int rgt = mid + 1;
        while (lft <= mid && rgt <= j)
        {
            if (arr[lft] <= arr[rgt])
            {
                v.push_back(arr[lft++]);
            }
            else
            {
                cnt += mid - lft + 1;
                v.push_back(arr[rgt++]);
            }
        }
        while (lft <= mid)
        {
            v.push_back(arr[lft++]);
        }
        while (rgt <= j)
        {
            v.push_back(arr[rgt++]);
        }

        for (int indx = i, k = 0; indx <= j; indx++, k++)
        {
            arr[indx] = v[k];
        }
    }
    void mergeSort(vector<int> &arr, int i, int j)
    {
        if (i >= j)
        {
            return;
        }
        int mid = i + (j - i) / 2;
        mergeSort(arr, i, mid);
        mergeSort(arr, mid + 1, j);
        merge(arr, i, mid, j);
    }
    int inversionCount(vector<int> &arr)
    {
        mergeSort(arr, 0, arr.size() - 1);
        return cnt;
    }
};