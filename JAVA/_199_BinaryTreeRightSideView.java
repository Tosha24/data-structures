// Trees, DFS, BFS, Binary Tree

// Problem: https://leetcode.com/problems/binary-tree-right-side-view/

// Time Complexity: O(N) 
// Space Complexity: O(H), H -> height of the tree

import java.util.ArrayList;
import java.util.List;

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

public class _199_BinaryTreeRightSideView {
    private static void solve(TreeNode node, int level, List<Integer> ans) {
        if (node == null)
            return;

        if (level == ans.size())
            ans.add(node.val);

        solve(node.right, level + 1, ans);
        solve(node.left, level + 1, ans);
    }

    public static List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        solve(root, 0, ans);
        return ans;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(
                1,
                new TreeNode(
                        2,
                        null,
                        new TreeNode(5)),
                new TreeNode(
                        3,
                        null,
                        new TreeNode(4)));
        List<Integer> result = rightSideView(root);
        for(int i : result){
            System.out.print(i + ", ");
        }
    }
}