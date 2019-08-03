#include <bits/stdc++.h>
using namespace std;

/*
leetcode 39.组合总和
给定一个无重复元素的数组 candidates 和一个目标数 target ，
找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。
示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]

思路：
回溯法，注意点：
1.因为题目中要求解集不能有重复的（[2,2,3],[2,3,2]是重复解集），
  所以传递一个start，每次从i=start开始，否则每次从i=0开始循环
2.if语句后面的return不要漏掉
3.时间复杂度：O(n^lgK)),K为target
*/

class Solution {
public:
    int tar;
    void helper(vector<int>& candi,int sum,vector<vector<int> >& ret,vector<int>& cur,int& start){
        if(sum==tar){
            ret.push_back(cur);
            return;
        }
        if(sum>tar){
            return;
        }
        for(int i=start;i<candi.size();++i){
            sum=sum+candi[i];
            cur.push_back(candi[i]);
            helper(candi,sum,ret,cur,i);
            sum=sum-candi[i];
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        tar=target;
        vector<vector<int>> ret;
        vector<int> cur;
        int start=0;
        helper(candidates,0,ret,cur,start);
        return ret;
    }
};
