class Solution
{
public:
    bool pythagoreanTriplet(vector<int> &arr)
    {
        int maxi = *max_element(arr.begin(), arr.end());
        vector<int> vis(maxi + 1, 0);
        for (auto x : arr)
        {
            vis[x] = 1;
        }
        for (int i = 1; i <= maxi; i++)
        {
            if (vis[i] == false)
                continue;
            for (int j = 1; j <= maxi; j++)
            {
                if (vis[j] == false)
                    continue;
                int a = i;
                int b = j;
                int c = sqrt(a * a + b * b);
                if (a * a + b * b == c * c && c <= maxi && vis[c] == 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// class Solution
// {
// public:
//     bool pythagoreanTriplet(vector<int> &arr)
//     {
//         sort(arr.begin(), arr.end());
//         int n = arr.size();
//         for (int i = 0; i < n; i++)
//         {
//             arr[i] = arr[i] * arr[i];
//         }
//         for (int i = n - 1; i >= 2; i--)
//         {
//             int lt = 0;
//             int rt = i - 1;
//             while (lt < rt)
//             {
//                 int sum = arr[lt] + arr[rt];
//                 if (sum == arr[i])
//                 {
//                     return true;
//                 }
//                 else if (sum > arr[i])
//                 {
//                     rt--;
//                 }
//                 else
//                 {
//                     lt++;
//                 }
//             }
//         }
//         return false;
//     }
// };