#include <bits/stdc++.h>
using namespace std;

/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。
现在你有两个符号 + 和 -。对于数组中的任意一个整数，
你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
 */

// 方法1：DP
/*
该问题可以转换为 Subset Sum 问题，从而使用 0-1 背包的方法来求解。

可以将这组数看成两部分，P 和 N，其中 P 使用正号，N 使用负号，有以下推导：
                  sum(P) - sum(N) = target
                           sum(P) = target + sum(N)
                  sum(P) + sum(P) = target + sum(N) +sum(P)
                       2 * sum(P) = target + sum(nums)
因此只要找到一个子集，令它们都取正号，并且和等于 (target + sum(nums))/2，就证明存在解。
 */


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        for(int val:nums){
            sum+=val;
        }
        if(sum<abs(S)) return 0;

        int tar=S+sum;
        if(tar&1) return 0;
        tar/=2;

        vector<int> dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();++i){
            for(int j=sum;j>=nums[i];--j){
                dp[j]=dp[j]+dp[j-nums[i]];
            }
        }
        return dp[tar];
    }
};


// 方法2：DP，空间占用比较大
// 思想：
// 列：一共有2sum+1个状态,表示计算能够得到的结果，存储的是计算方法的个数
// 行：nums[j],一共有nums.size()行，但每次只需要前一行用来更新，所以2行就够了
// 每来更新dp[val]时，都是从dp[val-nums[j]]或者dp[val+nums[j]]过来，所以是他们中方法的和,即
// dp[val]=dp[val-nums[j]]+dp[val+nums[j]]  需要注意数组不能越界
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        for(int val:nums)
            sum+=val;
        if(sum<abs(S)) return 0;
        vector<int> dp(2*sum+1,0);
        vector<int> dp1(dp);
        dp[sum]=1;
        for(int j=0;j<nums.size();++j){
            for(int val=-sum;val<=sum;++val){
                int add=val+sum+nums[j];
                int minus=val+sum-nums[j];
                int total=0;
                if(add>=0 && add <=2*sum) total+=dp[add];
                if(minus>=0 && minus<=2*sum) total+=dp[minus];
                dp1[val+sum]=total;
            }
            dp=dp1;
        }

        return dp[sum+S];
    }
};


// 方法3：回溯法
class Solution {
private:
    int cnt;
    int tar;
    void backtrace(const vector<int>& nums,int sum,int idx){
        if(idx>=nums.size()){
            if(sum==tar){
                cnt++;
            }
            return;
        }
        backtrace(nums,sum+nums[idx],idx+1);
        backtrace(nums,sum-nums[idx],idx+1);

    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        cnt=0;
        tar=S;
        backtrace(nums,0,0);
        return cnt;
    }
};

