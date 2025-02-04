class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> v(n, -1);
        stack<int> st;
        int i = n;
        while (i--)
        {
            while (!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                v[i] = -1;
            }
            else
            {
                v[i] = st.top();
            }
            st.push(arr[i]);
        }
        return v;
    }
};