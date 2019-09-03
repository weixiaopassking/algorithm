/*
题目描述
给定一个无序数组arr，其中元素可正、可负、可0。
求arr所有子数组中正数与负数个数相等的最长子数组的长度。

输入
5
1 -2 1 1 1
输出
2
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int sum=0;

    cin>>n;
    unordered_map<int,int> mp;
    mp[0]=-1;
    int ret=0;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        if(x>0) x=1;
        if(x<0) x=-1;
        sum=sum+x;
        if(mp.find(sum)!=mp.end()){
            ret=max(ret,i-mp[sum]);
        }else{
            mp[sum]=i;
        }
    }
    cout<<ret<<endl;

    return 0;
}
