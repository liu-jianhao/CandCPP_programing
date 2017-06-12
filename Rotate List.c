/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head || k == 0)
        return head;
    
    struct ListNode *lastnode = head;
    int n = 1;
    while(lastnode->next)
    {
        lastnode = lastnode->next;
        n++;
    }
    k = k%n;
    if(k == 0)
        return head;
        
    k = n - k;
    int i;
    lastnode->next = head;
    struct ListNode *newhead = head;
    for(i = 0; i < k - 1; i ++)
    {
        newhead = newhead->next;
    }
    head = newhead->next; 
    newhead->next = NULL;
    return head;
}
