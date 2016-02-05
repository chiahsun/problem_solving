class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (not headA or not headB) return 0;
        int lenA = 0, lenB = 0, d;
        ListNode *lastA, *lastB;
        for (ListNode *pa = headA; pa; pa = pa->next) {
            if (not pa->next) lastA = pa;
            ++lenA;
        }
        for (ListNode *pb = headB; pb; pb = pb->next) {
            if (not pb->next) lastB = pb;
            ++lenB;
        }
        if (lastA != lastB) return 0;
        ListNode *pa = headA, *pb = headB;
        if (lenA > lenB) { d = (lenA - lenB); while (d--) { pa = pa->next; } }
        else if (lenB > lenA) { d = (lenB - lenA); while (d--) { pb = pb->next; } }

        d = std::min(lenA, lenB);
        while (d--) {
            if (pa == pb) return pa;

            pa = pa->next, pb = pb->next;
        }
        return 0;
    }
};
