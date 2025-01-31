#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countPairs(vector<int> &arr, vector<int> &brr)
    {
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        int c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        long long cnt = 0;
        int n = brr.size();

        // Count occurrences of 0, 1, 2, 3, 4 in brr
        for (int x : brr)
        {
            if (x == 0)
                c0++;
            else if (x == 1)
                c1++;
            else if (x == 2)
                c2++;
            else if (x == 3)
                c3++;
            else if (x == 4)
                c4++;
        }

        // Iterate through arr and count valid pairs
        for (int x : arr)
        {
            if (x == 0)
            {
                // 0^b is always 0, so no valid pairs
                continue;
            }
            else if (x == 1)
            {
                // 1^b is 1 for any b, valid only when b=0
                cnt += c0;
            }
            else
            {
                // Count numbers in brr greater than x using binary search
                int idx = upper_bound(brr.begin(), brr.end(), x) - brr.begin();
                cnt += c0 + c1 + (n - idx);

                // Special case: 2^b > b^2 is false for b = 3, 4
                if (x == 2)
                {
                    cnt -= (c3 + c4);
                }
                else if (x == 3)
                {
                    cnt += c2; // 3^2 > 2^3, so add pairs with b=2
                }
            }
        }
        return cnt;
    }
};
