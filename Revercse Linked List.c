/*
	Reverse a singly linked list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL)
        return head;
        
    struct ListNode *p = head->next;
    head->next = NULL;
    while(p != NULL)
    {
        struct ListNode *ptmp = p->next;
        p->next = head;
        head = p;
        p = ptmp;
    }
    return head;
}
