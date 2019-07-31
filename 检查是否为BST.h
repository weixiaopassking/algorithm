#include <bits/stdc++.h>
using namespace std;

/*
请实现一个函数，检查一棵二叉树是否为二叉查找树。
给定树的根结点指针TreeNode* root，请返回一个bool，代表该树是否为二叉查找树。

二叉排序树，又叫二叉查找树，它或者是一棵空树；或者是具有以下性质的二叉树：

1.若它的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
2.若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
3.它的左右子树也分别为二叉排序树。

思路：
对于一颗树：
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
需要满足的条件有：
1.节点2要比节点1小，节点3要比焦点1大
2.节点5要比节点1小，节点6要比节点1大
后面一点比较重要。
*/


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Checker {
public:
    bool checkBST(TreeNode* root) {
        // write code here
        if(root==nullptr) return true;
        if(root->left ){
            if(root->left->val>=root->val)
                return false;
            if(root->left->right && root->left->right->val>=root->val )
                return false;
        }
        if(root->right){
            if(root->right->val<=root->val)
                return false;
            if(root->right->left && root->right->left->val <=root->val)
                return false;
        }
        if(!checkBST(root->left)) return false;
        if(!checkBST(root->right)) return false;
        return true;
    }
};
