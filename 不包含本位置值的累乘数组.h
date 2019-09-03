#include<bits/stdc++.h>
using namespace std;
/*
给定一个数组arr，返回不包含本位置值的累乘数组
例如，arr=[2,3,1,4]，返回[12, 8, 24, 6]，即除自己外，其他位置上的累乘
[要求]
时间复杂度为O(n)

思路：
1.right[i]保存从arr[n-1]连乘到arr[i]的值，这里一次反向O(n)的计算
2.用tmp保存从arr[0]连乘到arr[i-1]的数，这里一次正向O(n)循环计算每个结果tmp * right[i+1]并输出.
3.然后输出最后一个数tmp并回车

 */


int main(){
    int n;
    int p;
    cin>>n>>p;
    vector<long long > arr(n,0);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    vector<long long > right(arr);
    for(int i=n-2;i>=0;--i){
        right[i]=(right[i+1]*arr[i])%p;
    }

    long long  tmp=1;
    for(int j=0;j<n-1;++j){
        int res=tmp*right[j+1]%p;
        cout<<res<<" ";
        tmp=tmp*arr[j]%p;
    }

    cout<<tmp<<endl;

    return 0;
}
