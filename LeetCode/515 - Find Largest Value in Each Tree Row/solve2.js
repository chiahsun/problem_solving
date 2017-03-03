/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var largestValues = function(root) {
    var ans = [];
    function traverse(root, depth) {
        if (root === null) return;
        if (depth == ans.length)
            ans.push(root.val);
        else if (ans[depth] < root.val)
            ans[depth] = root.val;
        if (root.left) traverse(root.left, depth+1);
        if (root.right) traverse(root.right, depth+1);
    }
    traverse(root, 0);
    return ans;
};

