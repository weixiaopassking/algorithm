#include <bits/stdc++.h>
using namespace std;

/*
给定一个没有重复数字的序列，返回其所有可能的全排列。

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

思路：回溯法

 */

// 方法一：思想最直接，拿个数组存现在塞进去的所有数组，所有都塞进去了就是一个排列
class Solution {
public:
    void helper(vector<vector<int> >& ret,vector<int>& nums,vector<int>& cur,vector<int>& flag){
        if(cur.size()==nums.size()){
            ret.push_back(cur);
            return;
        }

        for(int i=0;i<nums.size();++i){
            if(flag[i]==1) continue;
            flag[i]=1;
            cur.push_back(nums[i]);
            helper(ret,nums,cur,flag);
            cur.pop_back();
            flag[i]=0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.empty()) return ret;

        vector<int>cur;
        vector<int> flag(nums.size(),0);
        helper(ret,nums,cur,flag);

        return ret;
    }
};



// 方法二：不断固定前面的数，全排列后面的数，直到要排的数只剩下一个
class Solution {
public:
    void helper(vector<vector<int> >& ret,vector<int>& nums,int start){
        if(start==nums.size()){
            ret.push_back(nums);
        }else{
            for(int i=start;i<nums.size();++i){
                // 固定从0~stat 的所有数字
                swap(nums[i],nums[start]);
                // 排列从 start+1 开始的所有数字
                helper(ret,nums,start+1);
                swap(nums[i],nums[start]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.empty()) return ret;

        helper(ret,nums,0);

        return ret;
    }
};
