class Solution
{
public:
    // Function to find intersection point in Y shaped Linked Lists.
    Node *intersectPoint(Node *head1, Node *head2)
    {
        int l1 = 0;
        int l2 = 0;
        Node *t1 = head1;
        Node *t2 = head2;
        while (t1 != nullptr)
        {
            l1++;
            t1 = t1->next;
        }
        while (t2 != nullptr)
        {
            l2++;
            t2 = t2->next;
        }
        t1 = head1;
        t2 = head2;
        if (l1 > l2)
        {
            for (int i = 0; i < l1 - l2; i++)
            {
                t1 = t1->next;
            }
        }
        else if (l1 < l2)
        {
            for (int i = 0; i < l2 - l1; i++)
            {
                t2 = t2->next;
            }
        }
        while (t1 != nullptr && t2 != nullptr)
        {
            if (t1 == t2)
            {
                return t1;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return nullptr;
    }
};