/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var findBottomLeftValue = function(root) {
    
    function find(root) {
        if (root === null)
            return [0, 0];
        if (root.left === null && root.right === null)
            return [1, root.val];
        var retl = find(root.left);
        var retr = find(root.right);
        var ret = ((retl[0] >= retr[0]) ? retl : retr);
        
        return [1+ret[0], ret[1]];
    } 
    
    var ret = find(root);
    return ret[1];
};
