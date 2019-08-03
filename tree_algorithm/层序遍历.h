#include <bits/stdc++.h>
#include "solution.h"
using namespace std;

/*
树的先序遍历
递归写法：
*/

//递归遍历(Recursive Solution)
//用递归遍历的缺点是需要一个数组来存储每一层的数
void levelOrderApi(TreeNode *root,vector<vector<int>>& res) {
    levelorderRe(root, 0, res);
}

void levelorderRe(TreeNode *root, int level, vector<vector<int>> &res) {
    if(!root) return;
    if(res.size() == level) res.push_back({});
    res[level].push_back(root->val);
    if(root->left) levelorderRe(root->left, level + 1, res);
    if(root->right) levelorderRe(root->right, level + 1, res);
}

// 非递归写法
void LevelOrder( TreeNode* root ){
    if(root==nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();q.pop();
        cout<<node->val<<" ";
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    }
}
