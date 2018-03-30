/* 合并两个已排序的链表，并将其作为一个新列表返回。新列表应该通过拼接前两个列表的节点来完成。 */

/* 示例： */

/* 输入：1->2->4, 1->3->4 */
/* 输出：1->1->2->3->4->4 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if(l1 == NULL)
                return l2;
            if(l2 == NULL)
                return l1;

            ListNode* l3 = NULL;
            if(l1->val > l2->val)
            {
                l3 = l2;
                l2 = l2->next;
            }
            else
            {
                l3 = l1;
                l1 = l1->next;
            }

            ListNode* head = l3;
            while(l1 != NULL && l2 != NULL){
                if(l1->val > l2->val)
                {
                    l3->next = l2;
                    l2 = l2->next;
                }
                else
                {
                    l3->next = l1;
                    l1 = l1->next;
                }
                l3 = l3->next;
            }

            if(l1)
                l3->next = l1;
            else
                l3->next = l2;
            return head;
        }
};
