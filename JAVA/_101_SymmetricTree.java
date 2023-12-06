// Trees, Binary Tree, Traversal

// Problem: https://leetcode.com/problems/symmetric-tree/

// TC: O(N)
// SC: O(N)

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class _101_SymmetricTree {
    private boolean isSymmetricBoth(TreeNode nleft, TreeNode nright) {
        if (nleft == null || nright == null)
            return nleft == nright;

        if (nleft.val != nright.val)
            return false;

        return isSymmetricBoth(nleft.left, nright.right) && isSymmetricBoth(nleft.right, nright.left);
    }

    public boolean isSymmetric(TreeNode root) {
        return root == null || isSymmetricBoth(root.left, root.right);
    }

    public static void main(String[] args) {
        // input: root = [1,2,2,3,4,4,3]
        // output: true

        // Input: root = [1,2,2,null,3,null,3]
        // Output: false
    }
}