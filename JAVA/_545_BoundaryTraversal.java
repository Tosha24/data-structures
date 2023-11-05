// Binary Trees, Stack, Inorder Traversal

// Problem: https://leetcode.com/problems/boundary-of-binary-tree/

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode() {
        this.val = 0;
        this.left = null;
        this.right = null;
    }

    public TreeNode(int x) {
        this.val = x;
        this.left = null;
        this.right = null;
    }

    public TreeNode(int x, TreeNode left, TreeNode right) {
        this.val = x;
        this.left = left;
        this.right = right;
    }
}

public class _545_BoundaryTraversal {
    private static boolean isLeaf(TreeNode node) {
        return (node.left == null && node.right == null);
    }

    private static void addLeftBoundary(TreeNode root, List<Integer> res) {
        TreeNode node = root.left;

        while (node != null) {
            if (!isLeaf(node))
                res.add(node.val);
            if (node.left != null)
                node = node.left;
            else
                node = node.right;
        }
    }

    private static void addLeaves(TreeNode root, List<Integer> res) {
        if (isLeaf(root)) {
            res.add(root.val);
            return;
        }

        if (root.left != null)
            addLeaves(root.left, res);
        if (root.right != null)
            addLeaves(root.right, res);
    }

    private static void addRightBoundary(TreeNode root, List<Integer> res) {
        TreeNode node = root.right;
        Stack<Integer> st = new Stack<>();

        while (node != null) {
            if (!isLeaf(node))
                st.push(node.val);
            if (node.right != null)
                node = node.right;
            else
                node = node.left;
        }

        while (!st.empty()) {
            res.add(st.peek());
            st.pop();
        }
    }

    public static List<Integer> boundaryTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;
        if (!isLeaf(root))
            res.add(root.val);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(
            1,
            new TreeNode(
                2,
                new TreeNode(
                    3,
                    null,
                    new TreeNode(
                        4,
                        new TreeNode(5),
                        new TreeNode(6)
                    )
                ),
                null
            ),
            new TreeNode(
                7,
                null,
                new TreeNode(
                    8,
                    new TreeNode(
                        9,
                        new TreeNode(10),
                        new TreeNode(11)
                    ),
                    null
                )
            )
        );
        List<Integer> result = boundaryTraversal(root);
        for (int i = 0; i < result.size(); i++) {
            System.out.print(result.get(i) + ", ");
        }
    }
}

// Time Complexity: O(H) for left boundary + O(H) for right boundary + O(n) for
// inorder traversal = O(n)
// Space Complexity: O(n) for extra stack use in right boundary = O(n)