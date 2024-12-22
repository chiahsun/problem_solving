/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        vector<Node*> nodes = vector<Node*>();
        nodes.push_back(nullptr);
        std::function<void(Node*)> dfs;
        dfs = [&](Node* p) {
            while (p->val >= std::size(nodes)) nodes.push_back(nullptr);
            nodes[p->val] = new Node(p->val);
            vector<Node*> neighbors = vector<Node*>();
            for (Node* pAdj : p->neighbors) {
                if (pAdj->val >= std::size(nodes) || nodes[pAdj->val] == nullptr) {
                    dfs(pAdj);
                }
                neighbors.push_back(nodes[pAdj->val]);
            }
            nodes[p->val]->neighbors = neighbors;
        };

        if (node) dfs(node);
        return (std::size(nodes) == 1) ? nodes[0] : nodes[1];
    }
};
