class Solution
{
public:
    Node *merge(Node *l1, Node *l2)
    {
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }
        Node *newHead = new Node(0);
        Node *t = newHead;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->data < l2->data)
            {
                t->bottom = l1;
                l1 = l1->bottom;
                t = t->bottom;
            }
            else
            {
                t->bottom = l2;
                l2 = l2->bottom;
                t = t->bottom;
            }
        }
        t->bottom = (!l1) ? l2 : l1;
        Node *result = newHead->bottom;
        delete newHead;
        return result;
    }
    Node *flatten(Node *root)
    {
        if (root == nullptr || root->next == nullptr)
        {
            return root;
        }
        Node *head = flatten(root->next);
        return merge(root, head);
    }
};