//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;

    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

// } Driver Code Ends
class MyStack
{
private:
    StackNode *top;

public:
    void push(int x)
    {
        StackNode *t = new StackNode(x);
        if (top == nullptr)
        {
            top = t;
            return;
        }
        t->next = top;
        top = t;
    }

    int pop()
    {
        if (top == nullptr)
        {
            return -1;
        }
        StackNode *t = top;
        int val = top->data;
        top = top->next;
        delete t;
        return val;
    }

    MyStack() { top = NULL; }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    cin.ignore();
    while (T--)
    {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num)
        {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            int QueryType = nums[i++];
            if (QueryType == 1)
            {
                int a = nums[i++];
                sq->push(a);
            }
            else if (QueryType == 2)
            {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
        cout << "~"
             << "\n";
        delete sq;
    }
}