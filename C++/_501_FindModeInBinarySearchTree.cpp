// ✔️ Tree, Binary Search Tree, DFS, Inorder Traversal

// Problem: https://leetcode.com/problems/find-mode-in-binary-search-tree/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<int> result;
    int currNum = 0, currFreq = 0, maxFreq = 0;

    void dfs(TreeNode* root){
        if(!root) return;
        
        // Traverse left subtree - inorder 
        dfs(root->left);

        // Now for the root node check for the number if already occured
        if(root->val == currNum) currFreq += 1;
        else{
            currNum = root->val;
            currFreq = 1;
        }

        if(currFreq > maxFreq){
            result.clear();
            maxFreq = currFreq;
        }

        if(currFreq == maxFreq) result.push_back(root->val);

        dfs(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return result;
    }
};

int main(){
    TreeNode* root = new TreeNode(
        7,
        new TreeNode(
            4,
            new TreeNode(
                4
            ),
            nullptr
        ),
        new TreeNode(
            8,
            new TreeNode(
                8
            ),
            new TreeNode(
                10
            )
        )
    );
    vector<int> result = Solution().findMode(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}