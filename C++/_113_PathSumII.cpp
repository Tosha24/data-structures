// Binary Tree

// Problem: https://leetcode.com/problems/path-sum-ii/

// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
#include <iostream>
#include<vector>
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
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
    void solve(TreeNode* root, int targetSum, int &sum, vector<int>& temp, vector<vector<int>>& ans){
        if(!root) return;

        sum += root->val;
        temp.push_back(root->val);

        if(isLeaf(root) && sum == targetSum){
            ans.push_back(temp);
            sum -= root->val;
            temp.pop_back();
            return;
        }

        solve(root->left, targetSum, sum, temp, ans);
        solve(root->right, targetSum, sum, temp, ans);

        sum -= root->val;
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;
        vector<vector<int>> ans;
        solve(root, targetSum, sum, temp, ans);
        return ans;
    }
};

int main() {
    // Input1: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    // Output1: [[5,4,11,2],[5,8,4,5]]

    // Input2: root = [1,2,3], targetSum = 5
    // Output2: []
    return 0;
}