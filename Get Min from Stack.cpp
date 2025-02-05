class Solution
{
    int minEle;
    stack<int> s;

public:
    stack<int> aux;
    int getMin()
    {
        if (aux.empty())
        {
            return -1;
        }
        return aux.top();
    }

    /*returns poped element from stack*/
    int pop()
    {
        if (s.empty())
        {
            return -1;
        }
        int val = s.top();
        s.pop();
        if (val == aux.top())
        {
            aux.pop();
        }
        return val;
    }

    void push(int x)
    {
        s.push(x);
        if (aux.empty() || aux.top() >= x)
        {
            aux.push(x);
        }
    }
};