// ✔️ Binary Tree, Inorder Traversal

// Problem: Code Studio

// Time Complexity: O(N)
// Space Complexity: O(N)

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
    bool solve(TreeNode* root, int target, vector<int>& ans){
        if(!root) return false;

        ans.push_back(root->val);
        if(root->val == target) return true;

        if(solve(root->left, target, ans) || solve(root->right, target, ans)) return true;

        ans.pop_back();
        return false;
    }
public:
    vector<int> getPath(TreeNode* root, int target){
        vector<int> ans;

        if(!root){
            return ans;
        }
        
        solve(root, target, ans);
        return ans;
    }  
};

int main(){
    TreeNode* root = new TreeNode(
        1,
        new TreeNode(
            2,
            new TreeNode(4),
            new TreeNode(
                5,
                new TreeNode(6),
                new TreeNode(7)
            )
        ),
        new TreeNode(3)
    );
    int target = 7;
    vector<int> result = Solution().getPath(root, target);
    for(int i: result){
        cout << i << ", ";
    }
    return 0;
}