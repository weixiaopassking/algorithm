#include <bits/stdc++.h>
#include <deque>
using namespace std;

/*
有一个整型数组arr和一个大小为w的窗口从数组的最左边滑到最右边，窗口每次向右边滑一个位置，
求每一种窗口状态下的最大值。（如果数组长度为n，窗口大小为w，则一共产生n-w+1个窗口的最大值
输入描述:
第一行输入n和w，分别代表数组长度和窗口大小
第二行输入n个整数
​
输出描述:
输出一个长度为n-w+1的数组res，res[i]表示每一种窗口状态下的最大值

输入
8 3
4 3 5 4 3 3 6 7
输出
5 5 5 4 6 7
 */

int main(){
    int n,w;
    cin>>n>>w;
    vector<int> arr(n,0);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    vector<int> res;
    deque<int> q;
    for(int i=0;i<n;++i){
        // !!!下面这句话很容易出错，存的是下标，所以用arr[q.back()]
        while(!q.empty() && arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);

        if(i>w-2){
            res.push_back(arr[q.front()]);
        }
        if(i-q.front()>=w-1){
            q.pop_front();
        }
    }
    int i=0;
    for(i=0;i<res.size()-1;++i) cout<<res[i]<<" ";
    cout<<res[i]<<endl;

    return 0;
}
