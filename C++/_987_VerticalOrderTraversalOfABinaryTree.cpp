// 2D Ordered_map, multiset, queue, Binary Tree, Traversal

// Problem: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root){
        map<int, map<int, multiset<int>>> nodes;        // 2D map
        queue<pair<TreeNode*, pair<int, int>>> todo;

        todo.push({root, {0, 0}});

        while(!todo.empty()){
            auto q = todo.front();
            todo.pop();
            TreeNode* node = q.first;
            int x = q.second.first, y = q.second.second;        // x is the level number, y is the vertical partition number
            
            nodes[y][x].insert(node->val);
            if(node->left) todo.push({node->left, {x+1, y-1}});
            if(node->right) todo.push({node->right, {x+1, y+1}});
        }

        vector<vector<int>> ans;
        for(auto row : nodes){
            vector<int> col;
            for(auto mp : row.second){
                col.insert(col.end(), mp.second.begin(), mp.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

int main()
{
    TreeNode* root = new TreeNode(
        3,
        new TreeNode(9),
        new TreeNode(
            20,
            new TreeNode(15),
            new TreeNode(7)
        )
    );
    vector<vector<int>> result = Solution().verticalTraversal(root);
    for(vector<int> sub : result){
        cout << "[";
        for(int num : sub){
            cout << num << ",";
        }
        cout << "],";
    }
    return 0;
}

// Time Complexity: O(N*logN*logN*logN)
// Space Complexity: O(N)