struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode prehead;
    struct ListNode *next = NULL;
    if (l1 == NULL)
    {
        return l2;
    }
    else if (l2 == NULL)
    {
        return l1;
    }
    next = &prehead;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            next->next = l1;
            l1 = l1->next;
            next = next->next;
        }
        else 
        {
            next->next = l2;
            l2 = l2->next;
            next = next->next;
        }
    }
    if (l1 != NULL)
    {
        next->next = l1;
    }
    else if (l2 != NULL)
    {
        next->next = l2;
    }
    return prehead.next;
}
