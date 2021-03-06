#include <bits/stdc++.h>
using namespace std;

/*
给定一个包含 n + 1 个整数的数组 nums，
其数字都在 1 到 n 之间（包括 1 和 n），
可知至少存在一个重复的整数。
假设只有一个重复的整数，找出这个重复的数。
 */

class Solution {
public:
        // 单独的数字(例如位置1里面存着1)自己形成一个环，我们无法进去，直接忽略就可以
        // 其余的数字会形成一个链表，nums[0]是整个链表的头指针
        // 重复数字会形成这个链表中的环，重复数字是环的入口
        // 这就是求链表的环的入口的一道题目了

        // 1.我们从nums[0]进入
        // 2.用快慢指针找到这个环里面的相遇点
        // 3.双指针法，一个从头开始走，一个从相遇点开始走，
        //   最终一定相遇在节点入口处
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[nums[0]];
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }

        slow=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
