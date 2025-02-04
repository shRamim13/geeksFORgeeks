Node *kReverse(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 1)
    {
        return head;
    }

    // Check if there are at least k nodes to reverse
    Node *temp = head;
    int count = 0;
    while (temp != nullptr && count < k)
    {
        temp = temp->next;
        count++;
    }

    if (count < k)
    {
        return head; // Not enough nodes, return as it is
    }

    // Reverse k nodes
    Node *prev = nullptr;
    Node *cur = head;
    Node *next = nullptr;
    int cnt = 0;

    while (cur != nullptr && cnt < k)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        cnt++;
    }

    // Recursively reverse the remaining part
    if (next != nullptr)
    {
        head->next = kReverse(next, k);
    }

    return prev; // New head of the reversed segment
}