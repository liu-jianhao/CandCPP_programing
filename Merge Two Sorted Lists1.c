/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result = NULL;
    struct ListNode *result_head = NULL;
    while(l1 || l2)
    {
        struct ListNode *next = NULL;
        if(l1 && !l2)
        {
            next = l1;
            l1 = l1->next;
        }
        else if(!l1 && l2)
        {
            next = l2;
            l2 = l2->next;
        }
        else if(l1->val < l2->val)
        {
            next = l1;
            l1 = l1->next;
        }
        else if(l1->val >= l2->val)
        {
            next = l2;
            l2 = l2->next;
        }
        
        if(!result)
        {
            result = next;
            result->next = NULL;
            result_head = result;
        }
        else
        {
            result->next = next;
            result = next;
        }
    }
    return result_head;
}
