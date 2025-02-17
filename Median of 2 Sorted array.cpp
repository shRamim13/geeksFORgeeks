#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &a, vector<int> &b)
{
    int m = a.size();
    int n = b.size();

    if (m > n)
    {
        return median(b, a); // Ensure binary search is on the smaller array
    }

    int low = 0, high = m;

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = (m + n + 1) / 2 - mid1;

        // Handling boundary conditions
        int p1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
        int p2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];

        int p3 = (mid1 == m) ? INT_MAX : a[mid1];
        int p4 = (mid2 == n) ? INT_MAX : b[mid2];

        if (p1 <= p4 && p2 <= p3)
        { // Valid partition found
            if ((m + n) % 2 == 1)
            {
                return max(p1, p2); // Odd length, median is the max of left partition
            }
            else
            {
                return (max(p1, p2) + min(p3, p4)) / 2.0; // Even length, average of middle elements
            }
        }
        else if (p1 > p4)
        {
            high = mid1 - 1; // Move left
        }
        else
        {
            low = mid1 + 1; // Move right
        }
    }

    return -1; // Should never reach here if input is valid
}