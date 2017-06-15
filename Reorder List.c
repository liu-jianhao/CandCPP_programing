/* 
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if (!head || !head->next) return;
    
    struct ListNode *fast = head;
    struct ListNode *mid = head;
    struct ListNode *pre_mid = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        pre_mid = mid;
        mid = mid->next;
    }
    
    // reverse link list since the middle of the list
    while (mid->next) {
        struct ListNode *then = mid->next;
        mid->next = then->next;
        then->next = pre_mid->next;
        pre_mid->next = then;
    }
    
    struct ListNode *h1 = head;
    struct ListNode *h2 = pre_mid->next;
    while (h1 != pre_mid) {
        struct ListNode *temp = h1->next;
        pre_mid->next = h2->next;
        h2->next = temp;
        h1->next = h2;
        h1 = h2->next;
        h2 = pre_mid->next;
    }
    
    return head;
}
