class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev(n, 0);
        vector<int> next(n, 0);
        prev[0] = arr[0];
        next[n - 1] = arr[n - 1];
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            prev[i] = max(prev[i - 1], arr[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            next[i] = max(next[i + 1], arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            ans += min(prev[i], next[i]) - arr[i];
        }
        return ans;
    }
};

/*
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        int lft=0;
        int rgt=n-1;
        int lftMax=arr[0];
        int rgtMax=arr[n-1];
        int cnt=0;
        while(lft<rgt){
            if(arr[lft]<arr[rgt]){
                if(arr[lft]>=lftMax){
                    lftMax=arr[lft];
                }else{
                    cnt+=(lftMax-arr[lft]);
                }
                lft++;
            }else{
                if(arr[rgt]>=rgtMax){
                    rgtMax=arr[rgt];
                }else{
                    cnt+=(rgtMax-arr[rgt]);
                }
                rgt--;
            }
        }
        return cnt;
    }
};

*/