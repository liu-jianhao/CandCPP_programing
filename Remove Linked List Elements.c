/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* temp = NULL;
    struct ListNode* out = NULL;
    if(head == NULL)
    {
        return head;
    }
    while(head->val == val)
    {
        if(head->next != NULL)
        {
        head = head->next;
        }
        else
        {
            head = NULL;
            return head;
        }
    }
    out = head;
    while(head->next != NULL)
    {
        temp = head->next;
        if(temp->val == val)
        {
            if(temp->next != NULL){
                head->next = temp->next;
            }
            else
            {
                head->next = NULL;
            }
        }
        else
        {
            head = head->next;
        }
    }
    return out;
}
