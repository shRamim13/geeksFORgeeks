
class Solution
{
public:
    Node *pairWiseSwap(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        // a=head
        // b=head->next
        // c=head->next->next
        Node *t = head->next;
        head->next = pairWiseSwap(head->next->next);
        t->next = head;
        return t;
    }
};