#include <cassert>
#include <iostream>

#define DEBUG_EXPR(expr) do { std::cerr << "*Debug " << #expr << " : " << (expr) << std::endl; } while (0)

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p_dummy = new ListNode(0), *p_prev = p_dummy, *p = head;
        p_prev->next = head;

        for (int i = 0; i < n; ++i) {
            if (not p) return head;
            p = p->next;
        }
        
        while (p) {
            p_prev = p_prev->next;
            p = p->next;
        }

        ListNode* p_remove = p_prev->next;
        p_prev->next = p_remove->next;
        if (head == p_remove)
            head = p_remove->next;
        delete p_remove; p_remove = nullptr;
        delete p_dummy; p_dummy = nullptr;
        
        return head;
    }
};

void print_list(ListNode* p) {
    while (p) {
        std::cout << p->val << " "; p = p->next;
    }
    std::cout << std::endl;
}

int main() {
#if 0
    {
    ListNode *p1 = new ListNode(1);

    print_list(Solution().removeNthFromEnd(p1, 1)); 
    }
#endif
    {
    ListNode *p1 = new ListNode(1), *p2 = new ListNode(2);
    p1->next = p2;

    print_list(Solution().removeNthFromEnd(p1, 1)); 
    }
#if 0
    {
    ListNode *p1 = new ListNode(1), *p2 = new ListNode(2);
    p1->next = p2;

    print_list(Solution().removeNthFromEnd(p1, 2)); 
    }
    for (int i = 1; i <= 5; ++i) {
    ListNode *p1 = new ListNode(1), *p2 = new ListNode(2), *p3 = new ListNode(3), *p4 = new ListNode(4), *p5 = new ListNode(5);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    print_list(Solution().removeNthFromEnd(p1, i)); 
    }
#endif

    return 0;
}
