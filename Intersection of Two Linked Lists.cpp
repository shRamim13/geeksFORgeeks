class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        unordered_map<int, int> mp;
        while (head2 != nullptr)
        {
            mp[head2->data]++;
            head2 = head2->next;
        }
        Node *Head = new Node(0);
        Node *newNode = Head;
        while (head1 != nullptr)
        {
            if (mp[head1->data] > 0)
            {
                newNode->next = new Node(head1->data);
                mp[head1->data]--;
                newNode = newNode->next;
            }
            head1 = head1->next;
        }
        return Head->next;
    }
};