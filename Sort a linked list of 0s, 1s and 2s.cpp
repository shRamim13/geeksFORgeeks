class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        int c0 = 0, c1 = 0, c2 = 0;
        while (head != nullptr)
        {
            if (head->data == 0)
                c0++;
            else if (head->data == 1)
                c1++;
            else
                c2++;
            head = head->next;
        }
        Node *newHead = new Node(0);
        Node *t = newHead;
        while (c0--)
        {
            t->next = new Node(0);
            t = t->next;
        }
        while (c1--)
        {
            t->next = new Node(1);
            t = t->next;
        }
        while (c2--)
        {
            t->next = new Node(2);
            t = t->next;
        }
        Node *result = newHead->next;
        delete newHead;
        return result;
    }
};