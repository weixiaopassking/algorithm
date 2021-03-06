#include <bits/stdc++.h>
using namespace std;

/*
计算最长递增子序列的最大个数

Input: [1,3,5,4,7]
Output: 2
Explanation: 2个最长增长子序列是 [1, 3, 4, 7] and [1, 3, 5, 7].

Input: [2,2,2,2,2]
Output: 5
Explanation: 最长的长度为1，有5个这样的子序列

思路：dp算法
// i<j && nums[i]<nums[j]:
// if length[j]<length[i]+1:
        count[j]=count[i]
// if length[j]==length[i]+1:
        count[j]+=count[i]
// 记录其中的maxlen；最后去对比一次，把所有的count加起来
 */

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int cnt=0;
        if(nums.empty()) return cnt;
        int n=nums.size(),maxlen=1;
        vector<int> length(n,1),count(n,1);

        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(nums[i]<nums[j]){
                    if(length[j]<length[i]+1){
                        length[j]=length[i]+1;
                        count[j]=count[i];
                    }
                    else if(length[j]==length[i]+1){
                        count[j]+=count[i];
                    }
                }
            }
            maxlen=max(maxlen,length[j]);
        }

        int rtnmax=0;
        for(int i=0;i<n;i++){
            if(length[i]==maxlen) rtnmax+=count[i];
        }
        return rtnmax;
    }
};
