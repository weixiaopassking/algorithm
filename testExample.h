/////////////////////////////////////
// 二叉树测试例子
//           1
//         /   \
//        2     3
//       / \   / \
//      4   5 6   7
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);

    vector<TreeNode*> arr;
    arr.push_back(root);
    arr.push_back(root->left);
    arr.push_back(root->right);
    arr.push_back(root->left->left);
    arr.push_back(root->left->right);
    arr.push_back(root->right->left);
    arr.push_back(root->right->right);

    // 调用函数进行测试
    // Solution s;
    // s.memberFunction();

    for(int i=0;i<arr.size();++i){
        delete arr[i];
    }
    return 0;
}

///////////////////////////////////////////
// 题目：字符串替换（把空格替换成%20的测试用例）
int main(){
    Solution s;
    char str[20]="hello word";
    s.replaceSpace(str,19);
    printf("str=%s",str);
    return 0;
}

////////////////////////////////////////////
// 题目：从先序遍历和中序遍历恢复二叉树的测试例子
// 二叉树的结构如下：
//              1
//           /     \
//          2       3
//        /        /  \
//       4        5    6
//        \           /
//         7         8
// 上面二叉树的先序为：vector<int> pre={1,2,4,7,3,5,6,8};
//           中序为：vector<int> vin={4,7,2,1,5,3,8,6};

// 按照先序遍历打印所有的节点值
void preprintallnode(TreeNode* node){
    if(node){
        cout<<node->val<<endl;
        preprintallnode(node->left);
        preprintallnode(node->right);
    }
}

int main(){
    Solution s;
    vector<int> pre={1,2,4,7,3,5,6,8};
    vector<int> vin={4,7,2,1,5,3,8,6};
    TreeNode* node=s.reConstructBinaryTree(pre,vin);
    preprintallnode(node);
    return 0;
}


int main(){
    Solution s;

    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    head->next->next-
    >next->next->next=head->next->next;

    ListNode* ret=s.EntryNodeOfLoop(head);
    cout<<ret->val<<endl;

    int a[4]={1,2,3,4};
    int *ptr=(int*)(&a+1);
    printf("%d",*(ptr-1));
    return 0;
}

//判断一棵树中有没有某部分子树
int main(){
    Solution s;

    TreeNode* root=new TreeNode(8);
    root->left=new TreeNode(8);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(9);
    root->left->right=new TreeNode(2);
    root->left->right->left=new TreeNode(4);
    root->left->right->right=new TreeNode(7);

    TreeNode* root2=new TreeNode(8);
    root2->left=new TreeNode(9);
    root2->right=new TreeNode(2);

    cout<<(s.HasSubtree(root,root2)==true?"true":"false");
    return 0;
}

//复杂链表的复制
//测试用例
RandomListNode* head=new RandomListNode(1);
head->next=new RandomListNode(2);
head->next->next= new RandomListNode(3);
head->next->next->next=new RandomListNode(4);
head->next->next->next->next=new RandomListNode(5);

head->random=head->next->next;
head->next->random=head->next->next->next->next;
head->next->next->next->random=head->next;



//二叉搜索树
//测试用例
//           9
//         /   \
//        4     11
//       / \   / \
//      2   5 10  12
TreeNode* root=new TreeNode(9);
root->left=new TreeNode(4);
root->right=new TreeNode(11);
root->left->left=new TreeNode(2);
root->left->right=new TreeNode(5);
root->right->left=new TreeNode(10);
root->right->right=new TreeNode(12);

