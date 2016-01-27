struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    int i;
    struct ListNode *pre = NULL;
    struct ListNode *end = NULL;
    struct ListNode *temp = NULL;
    struct ListNode result;

    if (NULL == head)
    {
        return head;
    }
    else if (NULL == head->next && 1 == n)
    {
        free(head);
        head = NULL;
        return head;
    }
        
    result.next = head;
    pre = &result;
    end = &result;

    for (i = 0; i <= n; i++)
    {
        end = end->next;
    }
    while(NULL != end)
    {
       pre = pre->next;
       end = end->next; 
    }
    temp = pre->next;
    pre->next = temp->next;
    free(temp);
    temp = NULL;
    return result.next;
    
}
