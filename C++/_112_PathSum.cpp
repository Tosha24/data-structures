// Binary Tree

// Problem: https://leetcode.com/problems/path-sum/

// Time Complexity: O(N)
// Space Complexity: O(N)

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    bool isLeaf(TreeNode *root)
    {
        return !root->left && !root->right;
    }
    bool solve(TreeNode *root, int targetSum, int &sum)
    {
        if (!root)
            return false;

        sum += root->val;

        if (isLeaf(root) && sum == targetSum)
            return true;

        if (solve(root->left, targetSum, sum) || solve(root->right, targetSum, sum))
            return true;

        sum -= root->val;
        return false;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        return solve(root, targetSum, sum);
    }
};

int main()
{
    // Input1: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    // Output1: true

    // Input2: root = [1,2,3], targetSum = 5
    // Output2: false

    return 0;
}