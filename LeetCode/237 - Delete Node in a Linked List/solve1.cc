class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* p_next = node->next;
        ListNode* p_next_next = node->next->next;
        node->val = p_next->val;
        node->next = p_next_next;
        delete p_next;
    }
};
