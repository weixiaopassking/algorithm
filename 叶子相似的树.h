#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
leetcode 872. 叶子相似的树 easy
请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
                   3
               /       \
              5         1
             /  \      /  \
           |6|    2   |9| |8|
                /  \
              |7|  |4|
举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。
如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

思路：
树的先序遍历
*/

class Solution {
public:
    void trans(TreeNode* root,vector<int>& array){
        if(root==nullptr) return;
        if(!root->left && !root->right) {
            array.push_back(root->val);
            return;
        }

        if(root->left) trans(root->left,array);
        if(root->right) trans(root->right,array);
    }


    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> array1,array2;
        trans(root1,array1);
        trans(root2,array2);
        if(array1.size()!=array2.size()) return false;
        for(int i=0;i<array1.size();++i){
            if(array1[i]!=array2[i]) return false;
        }
        return true;
    }
};
