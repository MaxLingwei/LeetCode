struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *node1 = NULL;
    struct ListNode *node2 = NULL;
    struct ListNode *temp = NULL;
    struct ListNode prehead;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }


    prehead.next = head;
    node1 = &prehead;
    node2 = &prehead;
    while (node2->next != NULL)
    {
        if (node2->next->val < x)
        {
            if (node1 != node2)
            {
                temp = node1->next;
                node1->next = node2->next;
                node2->next = node2->next->next;
            }
            else
            {
                node2 = node2->next;
            }
            node1 = node1->next;
        }
        else
        {
            node2 = node2->next;
        }
    }
    return prehead.next;
}
