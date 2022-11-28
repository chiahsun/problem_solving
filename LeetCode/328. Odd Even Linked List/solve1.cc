class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = head;
        ListNode* evenHead = (oddHead) ? oddHead->next : NULL;
        
        ListNode* cur = oddHead;
        while (cur) {
            ListNode* next = cur->next;
            ListNode* nextnext = next ? next->next : NULL;
            ListNode* nextnextnext = nextnext ? nextnext->next : NULL;
            cur->next = nextnext;
            if (next)
                next->next = nextnextnext;
            if (not nextnext) {
                cur->next = evenHead;
                break;
            }
            cur = nextnext;
        }

        return head;
    }
};
