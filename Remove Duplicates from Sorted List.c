/*
Given a sorted linked list, delete all duplicates 
such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head)
    	return head;

    int val = head->val;
    struct ListNode *current=head;
    while(current && current->next){
    	if(current->next->val == val){
    		struct ListNode *tmp = current->next->next;
    		current->next = tmp;
    	}
    	else{
    		val = current->next->val;
    		current = current->next;
    	}
    }
    return head;
}
