class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr or head->next == nullptr) return head;
        
        ListNode *p1 = head, *p2 = head->next;
        ListNode* newHead = p2;
        while (p1 and p2) {
            ListNode* p3 = p2->next;
            p2->next = p1, p1->next = p3;
            ListNode* p4 = (p3 != nullptr) ? p3->next : nullptr;
            if (p4 != nullptr)
                p1->next = p4;
            p1 = p3, p2 = p4;
        }
        return newHead;
    }
};
