// 2D TreeMap, multiset, queue, Binary Tree, Traversal

// Problem: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.TreeMap;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Pair {
    TreeNode node;
    int row;    
    int col;
    public Pair(TreeNode _node, int _row, int _col){    // parameterized constructor
        node = _node;
        row = _row;
        col = _col;
    }
}

public class _987_VerticalOrderTraversalOfABinaryTree {
    static public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> nodes = new TreeMap<>();
        Queue<Pair> todo = new LinkedList<Pair>(); 
        
        todo.offer(new Pair(root, 0, 0));

        while(!todo.isEmpty()){
            Pair q = todo.poll();
            TreeNode node = q.node;
            int x = q.row, y = q.col;

            if(!nodes.containsKey(y)){
                nodes.put(y, new TreeMap<>());
            }
            if(!nodes.get(y).containsKey(x)){
                nodes.get(y).put(x, new PriorityQueue<>());
            }

            nodes.get(y).get(x).offer(node.val);

            if(node.left != null){
                todo.offer(new Pair(node.left, x+1, y-1));
            }
            if(node.right != null){
                todo.offer(new Pair(node.right, x+1, y+1));
            }
        }

        List<List<Integer>> ans = new ArrayList<>();
        for(TreeMap<Integer, PriorityQueue<Integer>> row : nodes.values()){
            ans.add(new ArrayList<>());
            for(PriorityQueue<Integer> col : row.values()){
                while(!col.isEmpty()){
                    ans.get(ans.size() - 1).add(col.poll());
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(
            3,
            new TreeNode(9),
            new TreeNode(
                20,
                new TreeNode(15),
                new TreeNode(7)
            )
        );
        List<List<Integer>> result = verticalTraversal(root);
        System.out.println(result);
    }
}

// Time Complexity: O(N*logN*logN*logN) -> logN for TreeMap, logN for TreeSet,
// logN for PriorityQueue
// Space Complexity: O(N)

// Reference:
// https://www.w3schools.blog/hashmap-linkedhashmap-treemap-hashtable-java