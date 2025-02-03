class Solution
{
public:
    int getMiddle(Node *head)
    {
        if (head == nullptr)
        {
            return -1;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};