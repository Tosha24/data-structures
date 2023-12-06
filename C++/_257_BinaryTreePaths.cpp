// Binary Tree

// Problem: https://leetcode.com/problems/binary-tree-paths/

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
private: 
    void solve(TreeNode* node, vector<int>& temp, vector<string>& ans){
        temp.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr){
            string str;
            for(int i = 0; i < temp.size(); i++){
                str += to_string(temp[i]);
                if(i != temp.size() - 1){
                    str += "->";
                }
            }
            ans.push_back(str);
        }
        if(node->left != nullptr){
            solve(node->left, temp, ans);
        }
        if(node->right != nullptr){
            solve(node->right, temp, ans);
        }
        temp.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root){
        vector<string> ans;
        if(root == nullptr){
            return ans;
        }
        vector<int> values;
        solve(root, values, ans);
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
    vector<string> result = Solution().binaryTreePaths(root);
    for(string i: result){
        cout << i << ", ";
    }
    return 0;
}