#include <iostream>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *phead, ListNode *pend) {
    ListNode *pcur;
    for (pcur = phead; pcur != NULL; pcur = pcur->next) {
        std::cout << (pcur == NULL ? "null" : std::to_string(pcur->val)) << " ";
        if (pcur == pend) break;
    }
    std::cout << std::endl;
}

void print_list(ListNode *phead) {
    print_list(phead, NULL);
}
#include "solve1.h"

int main() {
    int N, x;
    std::cin >> N;

    ListNode *phead, *pcur;
    while (N--) {
        std::cin >> x;
        ListNode *p = new ListNode(x);

        if (phead == NULL) {
            phead = pcur = p;
        } else {
            pcur->next = p;
            pcur = p;
        }
    }

    print_list(phead);
    Solution s;
    s.sortList(phead);

    print_list(phead);

    return 0;
}
