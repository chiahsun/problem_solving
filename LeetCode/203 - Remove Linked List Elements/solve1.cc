/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (not head)
            return head;
        ListNode *dummy = new ListNode(0), *p_prev = dummy; 
        dummy->next = head;
        while (p_prev) {
            while (p_prev->next and p_prev->next->val == val) {
                ListNode* p_remove = p_prev->next;
                p_prev->next = p_remove->next; 
                delete p_remove; p_remove = nullptr;
            }
            p_prev = p_prev->next;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; dummy = nullptr;
        return newHead;
    }
};
