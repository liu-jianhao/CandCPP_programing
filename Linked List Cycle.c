/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast=head, *slow=head;
    while( slow && fast && fast->next ){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) 
            return true;
    }
    return false;
}
