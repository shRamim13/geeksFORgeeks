class Solution
{
public:
    Node *sortedMerge(Node *head1, Node *head2)
    {
        if (head1 == nullptr)
        {
            return head2;
        }
        if (head2 == nullptr)
        {
            return head1;
        }
        Node *t1 = head1;
        Node *t2 = head2;
        Node *newHead = new Node(0);
        Node *newNode = newHead;
        while (t1 != nullptr && t2 != nullptr)
        {
            if (t1->data <= t2->data)
            {
                newNode->next = t1;
                t1 = t1->next;
                newNode = newNode->next;
            }
            else
            {
                newNode->next = t2;
                t2 = t2->next;
                newNode = newNode->next;
            }
        }
        newNode->next = (t1 == nullptr) ? t2 : t1;
        return newHead->next;
    }
};