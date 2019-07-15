#include "solution.h"
#include <bits/stdc++.h>
using namespace std;


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

int main(void)
{
    Solution s;
    vector<int> nums={1,1,1,1,1};

    cout<<s.findTargetSumWays(nums,3)<<endl;
    return 0;

 }
