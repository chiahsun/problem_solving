#include <iostream>

#include "solve.h"


int main() {
    {
        ListNode* head = new ListNode(1);
        std::cout << (Solution().hasCycle(head)) << std::endl;
    }
    {
        ListNode* head = new ListNode(1);
        head->next = head;
        std::cout << (Solution().hasCycle(head)) << std::endl;
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        std::cout << (Solution().hasCycle(head)) << std::endl;
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        std::cout << (Solution().hasCycle(head)) << std::endl;
    }
    {
        ListNode* head = new ListNode(1);
        ListNode* p2 = head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = p2;
        std::cout << (Solution().hasCycle(head)) << std::endl;
    }
    return 0;
}
