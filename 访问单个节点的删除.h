#include <solution.h>
#include <bits/stdc++.h>
using namespace std;

/*
实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。
给定待删除的节点，请执行删除操作，若该节点为尾节点，返回false，否则返回true

思路：
1.用下一个节点的值复制到当前节点cur上来，覆盖当前节点，
2.cur->next=cur-next->next,修改为下下个节点
3.释放cur->next节点
*/

class Remove {
public:
    bool removeNode(ListNode* pNode) {
        // write code here
        if(pNode==nullptr) return false;

        if(pNode->next==nullptr){
            return false;
        }else{
            ListNode* next=pNode->next->next;
            pNode->val=pNode->next->val;
            pNode->next->next=nullptr;
            delete pNode->next;
            pNode->next=next;
        }

        return true;
    }
};
