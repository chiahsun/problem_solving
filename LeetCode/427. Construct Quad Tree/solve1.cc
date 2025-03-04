/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        std::function<Node*(int, int, int)> dfs;
        dfs = [&](int x, int y, int n) {
            if (n == 1) return new Node(grid[x][y], true);
            int hn = n / 2;
            Node* tl = dfs(x, y, hn);
            Node* tr = dfs(x, y+hn, hn);
            Node* bl = dfs(x+hn, y, hn);
            Node* br = dfs(x+hn, y+hn, hn);
            if ( tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
                 tl->val == tr->val && tr->val == bl->val &&  bl->val == br->val) {
                const int val = tl->val;
                delete tl; delete tr; delete bl; delete br;
                return new Node(val, true);
            }
            return new Node(0, false, tl, tr, bl, br);
        };
        return dfs(0, 0, grid.size());
    }
};

