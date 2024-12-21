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
            if (n == 1) return (Node*)nullptr;
            int hn = n / 2;
            Node* tl = dfs(x, y, hn), *tr = dfs(x, y+hn, hn), *bl = dfs(x+hn, y, hn), *br = dfs(x+hn, y+hn, hn);
            if (tl == nullptr && tr == nullptr && bl == nullptr && br == nullptr &&
              (grid[x][y] == grid[x][y+hn]) && (grid[x][y+hn] == grid[x+hn][y]) &&
              (grid[x+hn][y] == grid[x+hn][y+hn])) {
                return (Node*)nullptr;
            }
            return new Node(0, false,
                tl == nullptr ? new Node(grid[x][y], true) : tl,
                tr == nullptr ? new Node(grid[x][y+hn], true) : tr,
                bl == nullptr ? new Node(grid[x+hn][y], true) : bl,
                br == nullptr ? new Node(grid[x+hn][y+hn], true) : br);
        };
        Node* root = dfs(0, 0, grid.size());
        return (root) ? root : new Node(grid[0][0], true);
    }
};

