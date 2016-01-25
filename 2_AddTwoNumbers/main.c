/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int sum = 0;
    struct ListNode *pre = NULL;
    struct ListNode *result = NULL;
    struct ListNode *templ1 = NULL;
    struct ListNode *templ2 = NULL;

    
    result = pre;
    pre = NULL;
    templ1 = l1;
    templ2 = l2;
    while((templ1 != NULL) || (templ2 != NULL))
    {
        if (pre == NULL)
        {
            pre = (struct ListNode *)malloc(sizeof(struct ListNode));
        }
        else 
        {
            pre->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            pre = pre->next;
        }
        if (templ1 == NULL)
        {
            sum = templ2->val + carry;
            if (sum >= 10)
            {
                if (result == NULL)
                {
                    result = pre;
                }
                pre->val = sum - 10;
                carry = 1;
                pre->next = NULL;
            }
            else
            {
                if (result == NULL)
                {
                    result = pre;
                }
                pre->val = sum;
                carry = 0;
                pre->next = NULL;
            }
            templ2 = templ2->next;
        }
        else if (templ2 == NULL)
        {
            sum = templ1->val + carry;
            if (sum >= 10)
            {
                if (result == NULL)
                {
                    result = pre;
                }
                pre->val = sum - 10;
                carry = 1;
                pre->next = NULL;
            }
            else
            {
                if (result == NULL)
                {
                    result = pre;
                }
                pre->val = sum;
                carry = 0;
                pre->next = NULL;
            }
            templ1 = templ1->next;
        }
        else
        {

            sum = templ1->val + templ2->val + carry;
            if (sum >= 10)
            {
                if (result == NULL)
                {
                    result = pre;
                }
                pre->val = sum - 10;
                carry = 1;
                pre->next = NULL;
            }
            else
            {
                if (result == NULL)
                {
                    result = pre;
                }
                pre->val = sum;
                carry = 0;
                pre->next = NULL;
            }
            
            templ1 = templ1->next;
            templ2 = templ2->next;
        }
    }
    if (carry != 0)
    {
        pre->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        pre = pre->next;
        pre->val = carry;
        pre->next = NULL;
    }
    return result;
   
}