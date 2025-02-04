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




/*
class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head; // If empty or single node, return as it is.

        Node *zeroHead = nullptr, *zeroTail = nullptr;
        Node *oneHead = nullptr, *oneTail = nullptr;
        Node *twoHead = nullptr, *twoTail = nullptr;

        Node* curr = head;

        // Step 1: Divide the linked list into three lists
        while (curr) {
            if (curr->data == 0) {
                if (!zeroHead) zeroHead = zeroTail = curr;
                else {
                    zeroTail->next = curr;
                    zeroTail = curr;
                }
            } else if (curr->data == 1) {
                if (!oneHead) oneHead = oneTail = curr;
                else {
                    oneTail->next = curr;
                    oneTail = curr;
                }
            } else {
                if (!twoHead) twoHead = twoTail = curr;
                else {
                    twoTail->next = curr;
                    twoTail = curr;
                }
            }
            curr = curr->next;
        }

        // Step 2: Merge the three lists
        if (zeroTail) zeroTail->next = oneHead ? oneHead : twoHead;
        if (oneTail) oneTail->next = twoHead;
        if (twoTail) twoTail->next = nullptr;

        // Step 3: Return the new head
        return zeroHead ? zeroHead : (oneHead ? oneHead : twoHead);
    }
};

*/