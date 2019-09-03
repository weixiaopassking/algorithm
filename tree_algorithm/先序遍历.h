#include <bits/stdc++.h>
#include "solution.h"
using namespace std;

/*
树的先序遍历
递归写法：
*/

void PreOrderRe( TreeNode* root ){
    if(!root) return;
    printf("%d", root->val);
    PreOrderRe( root->left );
    PreOrderRe( root->right );
}

// 非递归写法
void PreOrder( TreeNode* root ){
    if(root==nullptr) return;
    TreeNode* node=root;
    stack<TreeNode*> st; /*创建并初始化堆栈S*/
    while( node || !st.empty() ){
        while(node){ /*一直向左并将沿途结点压入堆栈*/
            printf("%d", node->val);/*（访问） 打印结点*/
            st.push(node);
            node = node->left;
        }
        if(!st.empty()){
            node = st.top();st.pop(); /*结点弹出堆栈*/
            node = node->right; /*转向右子树*/
        }
    }
}
