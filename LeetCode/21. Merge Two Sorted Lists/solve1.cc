class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (not l1) return l2;
        if (not l2) return l1;
        
        ListNode *head, *cur;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        cur = head;
        while (l1 or l2) {
            if (not l2 or (l1 and (l1->val <= l2->val))) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        return head;
    }
};
