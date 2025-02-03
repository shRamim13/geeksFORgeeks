class Solution
{
public:
    int getKthFromLast(Node *head, int k)
    {
        if (head == nullptr)
        {
            return -1;
        }
        int len = 0;
        Node *t = head;
        while (t != nullptr)
        {
            len++;
            t = t->next;
        }
        if (k > len)
        {
            return -1;
        }
        t = head;
        for (int i = 0; i < (len - k); i++)
        {
            t = t->next;
        }
        return t->data;
    }
};