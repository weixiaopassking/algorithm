#include <bits/stdc++.h>
using namespace std;

/*
在未排序的数组中找到第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，
而不是第 k 个不同的元素。

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

用快速排序从小到大排序，每次把主元排进数组中，返回排入的位置
如果排入的位置小于目标位置，排序右侧；
如果排入的位置大于目标位置，排序左侧；
 */

class Solution {
public:
    int partition(vector<int> & nums,int low,int high){
        if(low>=high) return low;

        int i=low-1;
        int j=high;
        while(true){
            while(i<high && nums[++i]<nums[high]){};
            while(j>i && nums[--j]>nums[high]){};
            if(i<j) {
                swap(nums[i],nums[j]);
            }
            else break;
        }
        swap(nums[i],nums[high]);
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return -1;

        int low=0;int high=nums.size()-1;
        int index=nums.size()-k;
        while(low<=high){
            int res=partition(nums,low,high);
            if(index==res){
                return nums[index];
            }
            if(res>index)
                high=res-1;
            else
                low=res+1;
        }

        return nums[0];
    }
};

/*
最大堆的解法
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int sz=nums.size()-k+1;
        priority_queue<int> pq;
        for(int val:nums){
            pq.push(val);
            if(pq.size()>sz) pq.pop();
        }
        return pq.top();
    }
};
