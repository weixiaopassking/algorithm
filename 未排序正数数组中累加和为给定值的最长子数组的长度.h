/*
给定一个数组arr，该数组无序，但每个值均为正数，再给定一个正数k。
求arr的所有子数组中所有元素相加和为k的最长子数组的长度
例如，arr = [1, 2, 1, 1, 1], k = 3
累加和为3的最长子数组为[1, 1, 1]，所以结果返回3
[要求]
时间复杂度为O(n)，空间复杂度为O(1)
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];

    int ret=-1;
    int left=0;
    int right=0;
    int sum=arr[0];
    while(right<n){
        if(sum==k){
            ret=max(ret,right-left+1);
            // 更新左边
            // !!!先减arr[left],left++
            sum=sum-arr[left++];
        }else if(sum<k){
            right++;
            if(right==n) break;
            sum=sum+arr[right];
        }else{
            // !!!先减arr[left],left++
            sum=sum-arr[left++];
        }
    }
    cout<<ret<<endl;
    return 0;
}
