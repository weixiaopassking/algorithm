#include <bits/stdc++.h>
#include "solution.h".h"
using namespace std;

/*
寻找二叉树中指定结点的下一个结点（即中序遍历的后继）。
给定树的根结点指针TreeNode* root和结点的值int p，请返回值为p的结点的后继结点的值。
保证结点的值大于等于零小于等于100000且没有重复值，若不存在后继返回-1。

思路：
二叉树的中序遍历，分递归和非递归两种做法

*/

// 递归的写法
class Successor {
public:

    int flag;
    int val;
    int helper(TreeNode* root){
        if(root==nullptr ) return -1;
        int ret=helper(root->left);
        if(ret!=-1) return ret;
        if(flag) return root->val;
        if(root->val==val) flag=1;
        return helper(root->right);
    }

    int findSucc(TreeNode* root, int p) {
        // write code here
        val=p;
        flag=0;
        return helper(root);
    }
};


// 非递归的写法
class Successor {
public:
    int findSucc(TreeNode* root, int p) {
        // write code here
        stack<TreeNode*> st;
        TreeNode* node=root;
        int flag=0;
        while(node!=nullptr || !st.empty()){
            while(node){
                st.push(node);
                node=node->left;
            }
            node=st.top();st.pop();
            if(flag) return node->val;
            if(node->val==p) flag=1;
            node=node->right;
        }
        return -1;
    }
};
