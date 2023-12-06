// Binary Tree, Queue, Ordered Map

// Problem: GeeksForGeeks

// Time Complexity: O(N)
// Space Complexity: O(N)

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
    TreeNode(int x, TreeNode* left, TreeNode* right=nullptr) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> bottomView(TreeNode* root){
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        map<int,int> mp;

        q.push({root, 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int line = it.second;
            mp[line] = node->val;

            if(node->left != nullptr){
                q.push({node->left, line-1});
            }
            if(node->right != nullptr){
                q.push({node->right, line+1});
            }
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(
        3,
        new TreeNode(9),
        new TreeNode(
            20,
            new TreeNode(15),
            new TreeNode(7)
        )
    );
    vector<int> ans = Solution().bottomView(root);
    for(int i : ans){
        cout << i << ", ";
    }
    return 0;
}