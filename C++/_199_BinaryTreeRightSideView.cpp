// Trees, DFS, BFS, Binary Tree

// Problem: https://leetcode.com/problems/binary-tree-right-side-view/

// Time Complexity: O(N) 
// Space Complexity: O(H), H -> height of the tree

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void solve(TreeNode* node, int level, vector<int>& ans){
        if(!node) return;

        if(level == ans.size()) ans.push_back(node->val);
        solve(node->right, level + 1, ans);
        solve(node->left, level+1, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(
        1,
        new TreeNode(
            2,
            nullptr,
            new TreeNode(5)
        ),
        new TreeNode(
            3,
            nullptr,
            new TreeNode(4)
        )
    );
    vector<int> result = Solution().rightSideView(root);
    for(int i : result){
        cout << i << ", ";
    }
    return 0;
}