class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        // using dutch national flag algorithm introduced by Dijkstra
        int p0 = 0, p1 = 0, p2 = arr.size() - 1;
        while (p1 <= p2)
        {
            if (arr[p1] == 0)
            {
                swap(arr[p0++], arr[p1++]);
            }
            else if (arr[p1] == 1)
            {
                p1++;
            }
            else
            {
                swap(arr[p1], arr[p2--]);
            }
        }
    }
};

// class Solution
// {
// public:
//     void sort012(vector<int> &arr)
//     {
//         int c0 = 0, c1 = 0, c2 = 0;
//         for (auto x : arr)
//         {
//             if (x == 0)
//                 c0++;
//             else if (x == 1)
//                 c1++;
//             else
//                 c2++;
//         }
//         int k = 0;
//         for (; k < c0; k++)
//             arr[k] = 0;
//         for (; k < c0 + c1; k++)
//             arr[k] = 1;
//         for (; k < c0 + c1 + c2; k++)
//             arr[k] = 2;
//     }
// };