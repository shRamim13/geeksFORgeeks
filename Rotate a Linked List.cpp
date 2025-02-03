class Solution
{
public:
    Node *rotate(Node *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0)
        {
            return head;
        }
        Node *end = head;
        int len = 1;
        while (end->next != nullptr)
        {
            len++;
            end = end->next;
        }
        k = k % len;
        if (k == 0)
        {
            return head;
        }
        // k = len - k;     for rotate towards left
        end->next = head;
        Node *prevNewHead = head;
        for (int i = 0; i < len - k - 1; i++)
        {
            prevNewHead = prevNewHead->next;
        }
        Node *newHead = prevNewHead->next;
        prevNewHead->next = nullptr;
        return newHead;
    }
};
