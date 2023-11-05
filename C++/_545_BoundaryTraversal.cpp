// Binary Trees, Stack, Inorder Traversal

// Problem: https://leetcode.com/problems/boundary-of-binary-tree/

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

class Solution{ 
private:
    bool isLeaf(TreeNode* node);
    void addLeftBoundary(TreeNode*, vector<int>&);
    void addLeaves(TreeNode*, vector<int>&);
    void addRightBoundary(TreeNode*, vector<int>&);
public:
    vector<int> boundaryTraversal(TreeNode* root){
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->val);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};

bool Solution :: isLeaf(TreeNode* node){
    return (!node->left && !node->right);   // only if both are null
}

void Solution :: addLeftBoundary(TreeNode* root, vector<int>& res){
    TreeNode* node = root->left;

    while(node){
        if(!isLeaf(node)) res.push_back(node->val);
        if(node->left) node = node->left;
        else node = node->right;
    }
}

void Solution :: addLeaves(TreeNode* root, vector<int>& res){
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }

    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}

void Solution :: addRightBoundary(TreeNode* root, vector<int>& res){
    TreeNode* node = root->right;
    stack<int> st;

    while(node){
        if(!isLeaf(node)) st.push(node->val);
        if(node->right) node = node->right;
        else node = node->left;
    }

    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
}

int main(){
    TreeNode* root = new TreeNode(
        1,
        new TreeNode(
            2,
            new TreeNode(
                3,
                nullptr,
                new TreeNode(
                    4,
                    new TreeNode(5),
                    new TreeNode(6)
                )
            )
        ),
        new TreeNode(
            7,
            nullptr,
            new TreeNode(
                8,
                new TreeNode(
                    9,
                    new TreeNode(10),
                    new TreeNode(11)
                )
            )
        )
    );
    vector<int> result = Solution().boundaryTraversal(root);
    for (int i=0; i<result.size(); i++){
        cout << result[i] << ", ";
    }
    return 0;
}

// Time Complexity: O(H) for left boundary + O(H) for right boundary + O(n) for inorder traversal = O(n) 
// Space Complexity: O(n) for extra stack use in right boundary = O(n)