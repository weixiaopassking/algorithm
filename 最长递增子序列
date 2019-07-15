#include <bits/stdc++.h>
using namespace std;

/*
计算最长递增子序列的长度

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: 最长子序列是 [2,3,7,101],因此长度是4.

两步：
(1) if x is larger than all tails, append it, increase the size by 1
(2) if tails[i-1] < x <= tails[i], update tails[i]

input: [0, 8, 4, 12, 2]
dp: [0]
dp: [0, 8]
dp: [0, 4]
dp: [0, 4, 12]
dp: [0 , 2, 12]
虽然不是最长子序列，但是它的长度和最长子序列的长度相同
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int x:nums){
            int low=0;
            int high=dp.size();
            // 找到第一个大于x的数，下标保存在high
            while(low<high){
                int mid=(low+high)/2;
                if(dp[mid]<x) low=mid+1;
                else  high=mid;
            }

            if(high<dp.size())  dp[high]=x;
            else dp.push_back(x);
        }

        return dp.size();
    }
};


