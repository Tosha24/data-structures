// Trees, DFS, BFS, Binary Tree

// Problem: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Time Complexity: O(N)
// Space Complexity: O(N)

import java.util.*;

class Pair {
    TreeNode node;
    int line;    
    public Pair(TreeNode _node, int _line){    // parameterized constructor
        node = _node;
        line = _line;   
    }
}

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

public class _TopViewOfBinaryTree {
    static private List<Integer> topView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();

        if(root == null) return ans;

        Queue<Pair> q = new LinkedList<Pair>();       // node, line number
        Map<Integer, Integer> mp = new TreeMap<>();       // line number -> node val

        q.add(new Pair(root, 0));
        while(!q.isEmpty()){
            Pair p = q.remove();

            TreeNode node = p.node;
            int line = p.line;
            if(mp.get(line) == null) mp.put(line, node.val);

            if(node.left != null) q.add(new Pair(node.left, line - 1));
            if(node.right != null) q.add(new Pair(node.right, line + 1));
        }

        for(Map.Entry<Integer, Integer> entry : mp.entrySet()){
            ans.add(entry.getValue());
        }

        return ans;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(
                1,
                new TreeNode(
                        2,
                        new TreeNode(4),
                        new TreeNode(
                                5,
                                new TreeNode(6),
                                null)),
                new TreeNode(
                        3,
                        null,
                        new TreeNode(7)));
        List<Integer> result = topView(root);
        for (int i : result) {
            System.out.print(i + ", ");
        }
    }
}
