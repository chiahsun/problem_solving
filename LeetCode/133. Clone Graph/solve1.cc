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
        Node* nodes1[101] = {nullptr};
        Node* nodes2[101] = {nullptr};
        vector<Node*> processing = vector<Node*>();

        std::function<void(Node*)> createNodes;
        createNodes = [&](Node* p) {
            if (nodes1[p->val]) return;
            nodes1[p->val]  = p;
            processing.push_back((nodes2[p->val] = new Node(p->val)));
            for (Node* pAdj : p->neighbors) {
                if (!nodes1[pAdj->val])
                    createNodes(pAdj);
            }
        };

        std::function<void(Node*)> updateEdges;
        updateEdges = [&](Node* p) {
            auto neighbors = vector<Node*>();
            for (Node* pAdj : nodes1[p->val]->neighbors) {
                neighbors.push_back(nodes2[pAdj->val]);
            }
            nodes2[p->val]->neighbors = neighbors;
        };

        if (node) createNodes(node);
        for (Node* p2: processing)
            updateEdges(p2);
        return nodes2[1];
    }
};
