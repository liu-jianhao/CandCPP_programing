/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 ¡ú a2
                   ¨K
                     c1 ¡ú c2 ¡ú c3
                   ¨J            
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lena = 0, lenb = 0;
    struct ListNode *pa = headA, *pb = headB;
    
    for(; pa; pa = pa->next)
        lena++;
    for(; pb; pb = pb->next)
        lenb++;
        
    int i = 0;
    for(; i < (lena - lenb); i++)
        headA = headA->next;
    for(i = 0; i < (lenb - lena); i++)
        headB = headB->next;
        
    while(headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    
    return headA;
}
