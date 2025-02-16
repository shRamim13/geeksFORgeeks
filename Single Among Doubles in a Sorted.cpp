class Solution
{
public:
    int findOnce(vector<int> &arr)
    {
        int val = 0;
        for (int x : arr)
        {
            val ^= x;
        }
        return val;
    }
};

/*
class Solution {
  public:
    int findOnce(vector<int>& arr) {

        if(arr[0]!=arr[1]){
            return arr[0];
        }

        if(arr[arr.size()-1]!=arr[arr.size()-2]){
            return arr[arr.size()-1];
        }
        int l=1;
        int r=arr.size()-2;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]!=arr[mid-1]&&arr[mid]!=arr[mid+1]){
                return arr[mid];
            }
            else if(mid%2&&arr[mid]==arr[mid-1]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return -1;
    }
};

*/