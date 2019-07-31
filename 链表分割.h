#include <bits/stdc++.h>
using namespace std;

/*
以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。
注意：分割以后保持原来的数据顺序不变。

思路：
保存一个比x大的链表和一个比x小的链表
最后将两个链表合起来并返回。
*/

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* cur=pHead;
        ListNode* sptr=new ListNode(INT_MIN);
        ListNode* bptr=new ListNode(INT_MIN);
        ListNode* ssptr=sptr;
        ListNode* bbptr=bptr;
        while(cur){
            if(cur->val<x){
                ssptr->next=cur;
                ssptr=cur;
                cur=cur->next;
            }else{
                bbptr->next=cur;
                bbptr=cur;
                cur=cur->next;
            }
        }
        bbptr->next=nullptr;
        ssptr->next=bptr->next;
        ListNode* ret=sptr->next;
        delete sptr;
        delete bptr;
        return ret;
    }
};
