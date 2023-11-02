// ✔️ Tree, Binary Search Tree, DFS, Inorder Traversal

// Problem: https://leetcode.com/problems/find-mode-in-binary-search-tree/

import java.util.ArrayList;
import java.util.List;

import javax.swing.tree.TreeNode;

public class _501_FindModeInBinarySearchTree {
    private List<Integer> result = new ArrayList<>();
    private int currNum = 0, currFreq = 0, maxFreq = 0;

    private void dfs(TreeNode root){
        if(root == null) return;
        
        // Traverse left subtree - inorder 
        dfs(root.left);

        // Now for the root node check for the number if already occured
        if(root.val == currNum) currFreq += 1;
        else{
            currNum = root.val;
            currFreq = 1;
        }

        if(currFreq > maxFreq){
            result.clear();
            maxFreq = currFreq;
        }

        if(currFreq == maxFreq) result.add(root.val);

        dfs(root.right);
    }

    public int[] findMode(TreeNode root) {
        dfs(root);
        int[] resultArray = new int[result.size()];
        for(int i = 0; i < result.size(); i++){
            resultArray[i] = result.get(i);
        }
        return resultArray;
    }
}