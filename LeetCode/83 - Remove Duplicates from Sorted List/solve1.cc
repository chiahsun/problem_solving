class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (not head) return head;
        
        ListNode *cur = head, *p;
        while (cur) {
            p = cur->next;
            while (p and (p->val == cur->val)) {
                p = p->next;
            }
            cur->next = p;
            cur = p;
        }
        return head;
    }
};
