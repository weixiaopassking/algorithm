#include <bits/stdc++.h>
using namespace std;

/*
实现一个函数，检查二叉树是否平衡，平衡的定义如下，
对于树中的任意一个结点，其两颗子树的高度差不超过1。

给定指向树根结点的指针TreeNode* root，
请返回一个bool，代表这棵树是否平衡。
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

class Balance {
public:
    bool height(TreeNode* rt,int& high){
        if(rt==nullptr) {
            high=0;
            return true;
        }

        int height_l=0;
        int height_r=0;
        if(rt->left && height(rt->left,height_l)==false) return false;
        if(rt->right && height(rt->right,height_r)==false) return false;

        if(abs(height_r-height_l)>1) return false;
        high=max(height_r,height_l)+1;
        return true;
    }

    bool isBalance(TreeNode* root) {
        int high;
        return height(root,high);

    }
};
