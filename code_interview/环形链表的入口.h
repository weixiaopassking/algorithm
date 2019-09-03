#include <bits/stdc++.h>
using namespace std;

/*
思路：
“快慢指针相遇点到入环点的距离 ~= 头结点到入环点的距离”：
设起点为s，slow的速度为v，fast的速度为2v ，环入口为e，相遇点为p
设相遇时slow走的路程为S1，fast走的路程为S2，有：
S1= sp,S2=sp+k*pp(fast绕了n圈)，又有S2=2*S1=>sp+k*pp=2*sp,所以有：
sp=k*pp，sp=se+ep,k*pp = k*(ep+pe),所以se = (k-1)*(ep+pe)+pe这个等式很关键
换句话说，如果此时有两个指针一个从起点出发(s->e)，另一个从相遇点出发(pe+k-1个[ep+pe])，
以相同的速度前进，一定会在e点相遇即环点

步骤一：判断是否有环：快慢指针
步骤二：找出入环点：双指针

剑指offer上的思路是：
求得环的节点个数m，两个指针都从头开始，先让一个指针先移动m步，
然后两个指针一起走，直到两个指针相遇，先走的提前把环的路径长度走掉了，
所以肯定会在环的入口相遇
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr){
            return nullptr;
        }

        ListNode* slow=head->next;
        ListNode* fast=head->next->next;

        while(fast!=nullptr && slow!=nullptr){
            if(slow->next== nullptr || fast->next==nullptr){
                return nullptr;
            }
            if(slow==fast)
                break;
            slow=slow->next;
            fast=fast->next->next;
        }

        if(slow==nullptr || fast==nullptr) return nullptr;

        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;

    }
};

