#include <bits/stdc++.h>
#include "solution.h"
using namespace std;

/*
树的后序遍历
递归写法：
*/

void PostOrderRe( TreeNode* root ){
    if(!root) return;
    PostOrderRe( root->left );
    PostOrderRe( root->right);
    printf("%d ", root->val);
}

// 非递归写法
void PostOrder( TreeNode* root ){

}
