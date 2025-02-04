class Solution
{
public:
    Node *reverse(Node *head)
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
            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *t1 = reverse(slow);
        Node *t = head;
        while (t1 != nullptr)
        {
            if (t->data != t1->data)
            {
                return false;
            }
            t = t->next;
            t1 = t1->next;
        }
        return true;
    }
};