// Trees, DFS, BFS, Binary Tree

// Problem: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

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
public:
    vector<int> topView(TreeNode* root){
        vector<int> ans;

        if(!root) return ans;

        queue<pair<TreeNode*,int>> q;       // node, line number
        map<int, int> mp;       // line number -> node val

        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int line = p.second;
            if(mp.find(line) == mp.end()) mp[line] = node->val;

            if(node->left) q.push({node->left, line - 1});
            if(node->right) q.push({node->right, line + 1});
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }

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
                nullptr
            )
        ),
        new TreeNode(
            3,
            nullptr,
            new TreeNode(7)
        )
    );
    vector<int> result = Solution().topView(root);
    for(int i : result){
        cout << i << ", ";
    }
    return 0;
}