/* 
You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    struct ListNode* prev = NULL;
    struct ListNode* now = head;
    struct ListNode* next = head->next;
    do{
        now->next = prev;
        prev = now;
        now = next;
        next = next->next;
    }while(next!=NULL);
    now->next = prev;
    return now;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    struct ListNode head;
    head.next =NULL;
    head.val = 0;
    struct ListNode *p = &head;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = sum % 10;
        p->next = newNode;
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return reverseList(head.next);
}
