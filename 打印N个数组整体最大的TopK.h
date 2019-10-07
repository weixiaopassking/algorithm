#include <bits/stdc++.h>
using namespace std;

/*
有N个长度不一的数组，所有的数组都是有序的，请从大到小打印整体最大的前K个数。
例如，输入含有N行元素的二维数组可以代表N个一维数组。
219, 405, 538, 845, 971
148, 558
52, 99, 348, 691
再输入整数k=5，则打印：
Top 5: 971, 845, 691, 558, 538
[要求]
时间复杂度为O(klogk)，空间复杂度为O(klogk)

输入:
T, K分别表示数组个数，需要打印前K大的元素
接下来T行，每行输入格式如下：
开头一个整数N，表示该数组的大小，接下来N个已排好序的数表示数组内的数
输出:
从大到小输出输出K个整数，表示前K大。
 */

// 利用最大堆，每次把每一行中最大的一个数塞到最大堆里面，
// 取出一个数后，把数组内次大数塞进最大堆内，直到k个数打印出来
// 利用上了数组有序的给定条件

int main(){
    int t,k;
    cin>>t>>k;
    vector<vector<int>> arr(t,vector<int>());

    for(int i=0;i<t;++i){
        int n;
        cin>>n;
        for(int j=0;j<n;++j){
            int a;
            cin>>a;
            arr[i].push_back(a);
        }
    }

    auto cmp = [](vector<int> l,vector<int> r){ return l[0]<r[0];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);

    for(int i=0;i<t;++i){
        vector<int> nums(3,0);
        if(arr[i].size()==0) continue;
        nums[0]=arr[i].back();
        nums[1]=i;
        nums[2]=arr[i].size()-1;
        pq.push(nums);
    }

    vector<int> cur;

    while (--k>0) {
        cur=pq.top();
        pq.pop();
        cout<<cur[0]<<" ";
        if(cur[2]>0){
            vector<int> parr={arr[cur[1]][cur[2]-1],cur[1],cur[2]-1};
            pq.push(parr);
        }
    }

    cur=pq.top();
    cout<<cur[0]<<endl;

    return 0;
}


// 下面是用最小堆做的方法，没有利用数组是有序的这个条件
// 思路：最小堆只存K个最大堆数，有数字比堆顶大，那就插入这个数，然后弹出堆顶
//      最后就会剩下K个最大的数
int main(){
    int t,k;
    cin>>t>>k;
    vector<vector<int>> arr(t,vector<int>());

    for(int i=0;i<t;++i){
        int n;
        cin>>n;
        for(int j=0;j<n;++j){
            int a;
            cin>>a;
            arr[i].push_back(a);
        }
    }

    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<t;++i){
        for(int j=0;j<arr[i].size();++j){
            if(pq.size()<k){
                pq.push(arr[i][j]);
            }else{
                pq.push(arr[i][j]);
                pq.pop();
            }
        }
    }

    vector<int> res;
    while(pq.size()>0){
        res.push_back(pq.top());
        pq.pop();
    }

    for(int i=res.size()-1;i>0;--i){
        cout<<res[i]<<" ";
    }
    cout<<res[0]<<endl;

    return 0;
}
