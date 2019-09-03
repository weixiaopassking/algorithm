
#include <bits/stdc++.h>

using namespace std;

/*
用一个二叉查找树来维护当前已经插入的数组，小于等于该节点插入左子树内，
大于插入右子树内，递归调用。
这样，每次查询小于等于某个节点的节点数，分三种情况讨论，递归调用：
1.当前节点的值等于插入的节点的值，那么返回该节点的左子树数目就等于秩
2.当前节点的值大于插入的节点的值，那么递归调用左子树（因为该节点的本身
及其右子树都对秩没影响)
3.当前节点的值小于插入的节点的值，那么当前节点的所有左子树加上本身都是
该插入节点的秩，
然后加上插入的节点在右子树中的秩之和为改插入节点的秩

注意：1.只用记录当前节点的左子树的个数，2.每次都是先插再找出秩，所以每
次查找不会出现不在树中的情况。
*/


struct _TreeNode
{
    int val;
    int rank;     //秩
    int leftsize;    //左子树节点个数
    struct _TreeNode* left;
    struct _TreeNode* right;
    _TreeNode(int x):val(x),leftsize(0),left(NULL),right(NULL){}
};


//按照数据读入的顺序构建一棵二叉查找树,每次在将一个节点加入这棵树时便可以统计出它的秩
// 二插查找树的方法，时间复杂度O(nlgn)
class Rank
{
public:
    int push_node(_TreeNode* root,int x){
        int rank=0;
        _TreeNode* parent;
        while(root)   //找出插入点
        {
            parent=root;
            if(root->val>x){
                root->leftsize+=1;
                root=root->left;
            }else if(root->val==x){
                rank+=root->leftsize;
                root=root->right;
            }else{
                rank+=root->leftsize+1;
                root=root->right;
            }
        }

        _TreeNode* tmp= new _TreeNode(x);
        tmp->rank=rank;

        if(parent->val>x){
            parent->left=tmp;
        }else{
            parent->right=tmp;
        }
        return rank;
    }

    // 测试数据：A=[1,2...100000],22622ms
    vector<int> getRankOfNumber(vector<int> A, int n){
        vector<int> result;
        _TreeNode* node=new _TreeNode(A[0]);
        node->rank=0;
        result.push_back(node->rank);
        _TreeNode* root=node;
        for(int i=1;i<n;i++){
            result.push_back(push_node(root,A[i]));
        }
        return result;
    }
};


// 用红黑树的方法,找到节点，然后计算有多少个比它小的
// 总体时间复杂度：O(n^2)
class Rank {
public:
    // 测试数据：A=[1,2...100000],63308ms
    vector<int> getRankOfNumber(vector<int> A, int n) {
        // write code here
        multiset<int>::iterator iter;
        vector<int> result;
        multiset<int> set;
        for(int i = 0 ; i <n; ++i){
            set.insert(A[i]);
            iter = set.upper_bound(A[i]);
            int len = 0;
            multiset<int>::iterator cur = set.begin();
            while(cur != iter){
                len++;
                cur++;
            }
            result.push_back(len-1);
        }
        return result;
    }
};


int main ()
{
    clock_t start,finish;
    double totaltime;
    start=clock();

    /********************/
    // 计算运行时间
    // 程序主体
    Rank s1;
    vector<int> A;
    for(int i=1;i<=100000;++i) A.push_back(i);

    vector<int> ret=s1.getRankOfNumber(A,100000);

    // for(int val:ret) cout<<val<<" ";

    /********************/

    finish=clock();
    totaltime=(double)(finish-start);
    cout<<totaltime<<"ms"<<endl;

    return 0;
}


