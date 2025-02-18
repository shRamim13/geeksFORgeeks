class Solution
{
public:
    bool hasTripletSum(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        // vector<vector<int>>v;
        for (int i = 0; i < arr.size(); i++)
        {
            // if(i>0&&arr[i]==ar[i-1]){continue;}
            int l = i + 1;
            int r = arr.size() - 1;
            while (l < r)
            {
                int sum = arr[i] + arr[l] + arr[r];
                if (sum == target)
                {
                    return true;
                    /*
                    v.push_back({arr[i],arr[l],arr[r]});
                    while(l<r&&arr[l]==arr[l+1]){
                    l++;
                }
                while(l<r&&arr[r]==arr[r-1]){
                    r--;
                }
                l++;
                r--;

                    */
                }
                else if (sum < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return false;
        // return v;
    }
};