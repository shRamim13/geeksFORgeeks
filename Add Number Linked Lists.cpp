class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = nullptr;
        Node *cur = head;
        while (cur)
        {
            Node *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    Node *addTwoLists(Node *num1, Node *num2)
    {
        Node *head = new Node(0); // Dummy node
        Node *t = head;

        num1 = reverse(num1);
        num2 = reverse(num2);

        int carry = 0;

        while (num1 || num2 || carry)
        {
            int sum = carry;

            if (num1)
            {
                sum += num1->data;
                num1 = num1->next;
            }

            if (num2)
            {
                sum += num2->data;
                num2 = num2->next;
            }

            carry = sum / 10;
            sum %= 10;

            t->next = new Node(sum);
            t = t->next;
        }

        Node *result = reverse(head->next);
        delete head;
        while (result && result->data == 0)
        {
            result = result->next;
        }
        return result ? result : new Node(0);
    }
};