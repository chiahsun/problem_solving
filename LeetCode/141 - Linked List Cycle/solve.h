#ifndef SOLVE_H
#define SOLVE_H

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) { }
};

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if (head == nullptr) return false;
            ListNode *p1 = head, *p2 = head->next; 

            while (p1 != p2) {
                p1 = p1->next;
                if (p2 == nullptr or p2->next == nullptr)
                    return false;
                p2 = p2->next->next;
            }
            return true;
        }
};
#endif // SOLVE_H
