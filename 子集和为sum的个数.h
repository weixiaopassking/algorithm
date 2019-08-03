#include <bits/stdc++.h>
using namespace std;

/*
获得子集和为sum的个数；

输入: nums: [1, 1, 1, 1, 1], S: 4
输出: 5
解释:

任选其中4个数，加起来的和都是4，C(4)(5)=C(1)(5)
一共有5中方法。
 */

/*
思想：
dp算法，列表示得到的和的状态（0~sum），列表示nums.size()个数，每次获得一个。
得到目前的和为tar的方法有两种：
1.不加上现在的数nums[i],dp[tar]本来就有的
2.从dp[tar-nums[i]那边得到的;
 */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int tar) {
        int sum=0;
        for(int val:nums){
            sum+=val;
        }
        if(sum<tar) return 0;

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

