class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (not head) return head;
        
        std::stack<ListNode*> st;
        ListNode* cur = head;
        while (cur->next) {
            st.push(cur);
            cur = cur->next;
        }
        ListNode* newHead = cur;
        while (not st.empty()) {
            ListNode* tp = st.top(); st.pop();
            cur->next = tp;
            cur = cur->next;
        }
        cur->next = NULL;
        
        return newHead;
    }
};
