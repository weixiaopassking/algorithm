#include <bits/stdc++.h>
using namespace  std;
/*
leetcode 410. 分割数组的最大值 hard
给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。
设计一个算法使得这 m 个子数组各自和的最大值最小。(1 ≤ n ≤ 1000,1 ≤ m ≤ min(50, n))

输入:nums = [7,2,5,10,8],m = 2
输出:18
解释:[7,2,5] 和 [10,8]

思路：
有两种方法做这种，一种是用dp来做，另一种是用二分查找做。
 */

/*
 二分查找的思路：
 1.首先在sum以及maxval（maxt）中找个邻界值mid
 2.然后按mid给这个数组分组，直到分的组刚好小于等于m，说明如果我分多的组，总和可以更小
 3.当这个界限确定下来之后，就是返回值（l=r）
 */

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int len=nums.size();
        if(len==0) return 0;
        int sum=0;int maxt=INT_MIN;
        for(int val:nums){
            sum+=val;
            maxt=max(maxt,val);
        }
        if(m==1) return sum;
        if(len<=m){
            return maxt;
        }
        int l=maxt,r=sum;
        int mid;
        while(l<r){
            mid=(r+l)/2;
            if(help(mid,nums,m)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return r;
    }

    bool help(int mid,vector<int>& nums,int m){
        int sum=0;
        int count=1;
        for(int val:nums){
            sum+=val;
            if(sum>mid){
                sum=val;
                count++;
                if(count>m){
                    return false;
                }
            }
        }
        return true;
    }
};


/* dp的思路:
 1.状态转移方程：dp[k][j]=min(dp[k][j],max(dp[t][j-1],sub[k]-sub[t]));
    1.1 dp[k][j]:表示的是nums[0..k-1]分成j组，所有子数组中的最大和，
    1.2 sub[k]:表示从nums[0]累加到nums[k-1]得到的总和sum(sub[0]=0,sub[1]=sub[0],sub[2]=sub[0]+sub[2])
    1.3 方程的解释：已经知道了dp[t][j-1]的情况下，后面再增加k-t个数成为一组，计算总和，并对每一个dp[k][j]不断进行更新
 2.最后返回dp[n][m]为以nums[n-1]结尾的分割数组
 */

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if(nums.empty()) return 0;
        int n=nums.size();
        vector<long> sub(n+1,0);
        vector<vector<long>> dp(n+1,vector<long>(m+1,INT_MAX));
        for(int i=0;i<nums.size();++i){
            sub[i+1]=sub[i]+nums[i];
        }
        dp[0][0]=0;

        for(int k=1;k<=n;++k){
            for(int j=1;j<=m;++j){
                for(int t=0;t<k;++t){
                    dp[k][j]=min(dp[k][j],max(dp[t][j-1],sub[k]-sub[t]));
                }
            }
        }
        return dp[n][m];
    }
};
