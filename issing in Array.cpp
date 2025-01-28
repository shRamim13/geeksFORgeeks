class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        long long sum = 0;
        long long n = arr.size() + 1;
        for (auto x : arr)
        {
            sum += x;
        }
        return (n * (n + 1) / 2) - sum;
    }
};

/*
class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int xorSum = 0;

        // XOR all elements in the array
        for (auto x : arr) {
            xorSum ^= x;
        }

        // XOR all numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            xorSum ^= i;
        }

        return xorSum;  // The missing number is the remaining XOR result
    }
};


*/