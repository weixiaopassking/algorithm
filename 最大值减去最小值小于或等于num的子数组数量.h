/*
题目描述
给定数组 arr 和整数 num，共返回有多少个子数组满足如下情况：
max(arr[i...j] - min(arr[i...j]) <= num
max(arr[i...j])表示子数组arr[i...j]中的最大值，min[arr[i...j])表示子数组arr[i...j]中的最小值。

输入描述:
第一行输入两个数 n 和 num，其中 n 表示数组 arr 的长度
第二行输入n个整数

输出描述:
输出给定数组中满足条件的子数组个数

示例
输入
5 2
1 2 3 4 5
输出
12

思路：
1.计算以arr[i]为第一个元素的不同子数组；
2.qmin和qmax分别保存当前窗口中的最大值和最小值队列；
3.如果arr[i..j]符合要求，那么arr[i..j-1]也肯定符合要求
4.如果arr[i..j]不符合要求，那么arr[i..j+1]也肯定不符合要求
5.不停移动j，直到当前数组不符合要求，然后停下来移动一个i

 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int num;
    cin>>n>>num;
    vector<int> arr(n,0);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    if(n<0){
        cout<<0<<endl;
        return 0;
    }

    deque<int> qmax;
    deque<int> qmin;
    int i=0;
    int j=0;
    int res=0;
    while(i<arr.size()){
        while(j<n){
            while(!qmax.empty() && arr[qmax.back()] <=arr[j]){
                qmax.pop_back();
            }
            qmax.push_back(j);

            while(!qmin.empty() && arr[qmin.back()]>=arr[j]){
                qmin.pop_back();
            }
            qmin.push_back(j);

            if(arr[qmax.front()]-arr[qmin.front()]>num){
                break;
            }
            j++;
        }
        while(!qmax.empty() && qmax.front()<=i){
            qmax.pop_front();
        }
        while(!qmin.empty() && qmin.front()<=i){
            qmin.pop_front();
        }
        res+=j-i;
        i++;
    }

    cout<<res<<endl;
    return 0;
}
