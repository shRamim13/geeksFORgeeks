class Solution
{
public:
    bool isParenthesisBalanced(string &s)
    {
        stack<char> st;
        for (auto x : s)
        {
            if (x == '(' || x == '{' || x == '[')
            {
                st.push(x);
            }
            else
            {
                if (st.empty())
                    return false;
                if ((x == ')' && st.top() == '(') || (x == '}' && st.top() == '{') || (x == ']' && st.top() == '['))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};