struct ListNode
{
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode *node)
{
    struct ListNode *temp = NULL;
    temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    free(temp);
    temp = NULL;
}
