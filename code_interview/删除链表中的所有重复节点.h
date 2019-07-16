#include <solution.h>
#include <bits/stdc++.h>
using namespace std;

/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:
输入: 1->2->3->3->4->4->5
输出: 1->2->5

示例 2:
输入: 1->1->1->2->3
输出: 2->3

思想：
当前节点cur和cur的下一个节点比较
1.cur->val==cur->next->val
    1) 如果cur->val==cur->next->next->val,
    把cur->next删除，把cur的下下个节点链接到cur上，重新循环
    2) cur->val！=cur->next->next->val
    删除cur和cur->next,cur=cur->next->next,last和ret更新

2.cur->val！=cur->next->val && ret==nullptr
找到第一个不重复的节点作为返回的头指针

3.找到非第一个不重复的节点
不用删除，cur复制为下一个节点
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode* last=nullptr;
        ListNode* cur=head;
        ListNode* next=head->next->next;
        ListNode* ret=nullptr;

        while(cur!=nullptr && cur->next!=nullptr){
            if(cur->val==cur->next->val){
                next=cur->next->next;
                if(next!=nullptr && cur->val==next->val){
                    delete cur->next;
                    cur->next=next;
                    continue;
                }
                delete cur->next;
                delete cur;
                cur=next;
                if(last){
                    last->next=cur;
                }else{
                    ret=cur;
                }
            }else if(ret==nullptr){
                ret=cur;
                last=cur;
                cur=cur->next;
            }else{
                last=cur;
                cur=cur->next;
            }
        }
        return ret;
    }
};
