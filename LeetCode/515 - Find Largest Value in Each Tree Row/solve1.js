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
        // console.log('root: ', root.val, ' ans : ' , ans);
        if (ans.length <= depth)
            ans.push(root.val);
        else if (ans[depth] < root.val)
            ans[depth] = root.val;
        if (root.left) traverse(root.left, depth+1);
        if (root.right) traverse(root.right, depth+1);
    }
    traverse(root, 0);
    return ans;
};

function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

function buildTree(array) {
    if (!array || !array.length) return null;

    function build(cur, i) {
        // console.log('cur : ', cur.val, ' i : ', i);
        var pos = 2*i+1;
        if (pos < array.length) {
            cur.left = new TreeNode(array[pos]);
            build(cur.left, pos);
        }
        ++pos;
        if (pos < array.length) {
            cur.right = new TreeNode(array[pos]);
            build(cur.right, pos);
        }
    }

    var root = new TreeNode(array[0]);
    build(root, 0);
    return root;
}

var root = buildTree([1,3,2,5,3,null,9]);
console.log(largestValues(root));
