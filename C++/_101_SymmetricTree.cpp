// Trees, Binary Tree, Traversal

// Problem: https://leetcode.com/problems/symmetric-tree/

// TC: O(N)
// SC: O(N)

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
public:
    bool isSymmetricBoth(TreeNode *nleft, TreeNode *nright)
    {
        if (nleft == nullptr || nright == nullptr)
            return nleft == nright;

        if (nleft->val != nright->val)
            return false;

        return isSymmetricBoth(nleft->left, nright->right) && isSymmetricBoth(nleft->right, nright->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        return root == nullptr || isSymmetricBoth(root->left, root->right);
    }
};

int main()
{
    // input: root = [1,2,2,3,4,4,3]
    // output: true

    // Input: root = [1,2,2,null,3,null,3]
    // Output: false
    return 0;
}