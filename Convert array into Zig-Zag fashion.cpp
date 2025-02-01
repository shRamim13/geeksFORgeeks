class Solution
{
public:
    void zigZag(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size() - 1; i = i + 2)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
};

/*
class Solution {
  public:
    void zigZag(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            if ((i % 2 == 0 && arr[i] > arr[i + 1]) ||
                (i % 2 == 1 && arr[i] < arr[i + 1])) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
};


*/