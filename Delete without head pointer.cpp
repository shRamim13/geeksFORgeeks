class Solution
{
public:
    // Function to delete a node without any reference to the head pointer.
    void deleteNode(Node *del_node)
    {
        if (del_node == nullptr || del_node->next == nullptr)
        {
            return;
        }
        del_node->data = del_node->next->data;
        Node *t = del_node->next;
        del_node->next = del_node->next->next;
        delete t;
    }
};