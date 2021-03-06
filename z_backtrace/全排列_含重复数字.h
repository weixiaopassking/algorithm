#include <bits/stdc++.h>
using namespace std;

/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

思路：回溯法

 */

// 方法一：不断固定前面的数，全排列后面的数，直到要排的数只剩下一个
// 判断交换的时候这两个下标不同的数是否相等
class Solution {
public:
    bool judge(vector<int> &nums,int st,int end){
        if(st==end) return true;
        for(int i=st;i<end;++i){
            if(nums[i]==nums[end])
                return false;
        }
        return true;
    }

    void helper(vector<vector<int> >& ret,vector<int>& nums,int start){
        if(start==nums.size()){
            ret.push_back(nums);
        }else{
            for(int i=start;i<nums.size();++i){
                if(!judge(nums,start,i)) continue;

                swap(nums[i],nums[start]);
                // 排列从 start+1 开始的所有数字
                helper(ret,nums,start+1);
                swap(nums[i],nums[start]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.empty()) return ret;

        helper(ret,nums,0);

        return ret;
    }
};



// 方法二：数组的全排列+set去重
// 占用空间太多，不建议使用
// 省略实现过程
//
