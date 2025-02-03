class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                break;
            }
        }
        if (slow != fast)
        {
            return;
        }
        slow = head;
        if (slow == fast)
        {
            while (fast->next != slow)
            {
                fast = fast->next;
            }
        }
        else
        {
            while (fast->next != slow->next)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        fast->next = nullptr;
    }
};