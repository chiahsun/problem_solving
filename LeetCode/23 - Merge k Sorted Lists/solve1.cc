/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct Node {
    int index, value;
    Node(int idx, int val) : index(idx), value(val) { }
    
    bool operator < (const Node & other) const {
        return value > other.value;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr, *p;
        
        std::priority_queue<Node> pq;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                pq.push(Node(i, lists[i]->val));
                lists[i] = lists[i]->next;
            }
        }
        
        while (!pq.empty()) {
            Node node = pq.top(); pq.pop();
            if (!head) {
                head = p = new ListNode(node.value);
            } else {
                p->next = new ListNode(node.value);
                p = p->next;
            }
            
            if (lists[node.index]) {
                pq.push(Node(node.index, lists[node.index]->val));
                lists[node.index] = lists[node.index]->next;
            }
        }
        
        return head;
    }
};
