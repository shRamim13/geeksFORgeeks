class Solution
{
public:
    Node *reverseList(struct Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        Node *prev = nullptr;
        Node *cur = head;
        Node *next = nullptr;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = prev;
            prev = next;
            cur = next;
        }
        return prev;
    }
};