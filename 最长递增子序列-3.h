#include <bits/stdc++.h>
using namespace std;

/*
给定数组arr，设长度为n，输出arr的最长递增子序列。
（如果有多个答案，请输出其中字典序最小的）

输入
5
1 2 8 6 4
输出
1 2 4
说明
其最长递增子序列有3个，（1，2，8）、（1，2，6）、（1，2，4）其中第三个字典序最小，
故答案为（1，2，4）

思路：
1.按照最长递增子序列-1的算法，用二分查找的方式维护一个dp数组，
2.另外再维护一个len[i]数组，表示以arr[i]结尾的数组的长度
3.上面两个计算完之后，开始找字典序最小的递增子序列，方式如下：
  记录一个lastindex，表示当前最长的数组 的结尾的数字下标，
  从lastindex开始，前面某一个len[i]==len[lastindex]-1,同时还满足
  arr[i]<arr[lastindex],那这个数就是在这条路径上的数
  直到i<0为止

 */

int findbig(vector<int>& num,int val){
    int low=0;
    int high=num.size()-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(num[mid]<val){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    return low;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    vector<int> dp;
    vector<int> len;
    int lastindex=0;
    int maxlen=0;

    for(int i=0;i<n;++i){
        if(dp.empty() || arr[i]>dp.back()){
            dp.push_back(arr[i]);
            len.push_back(dp.size());
            maxlen=dp.size();
            lastindex=i;
        }else{
            int index=findbig(dp,arr[i]);
            //int index=upper_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
            dp[index]=arr[i];
            len.push_back(index+1);
            if(maxlen==index+1) lastindex=i;
        }
    }

    stack<int> res;
    int k=0;
    for(;lastindex>=0;lastindex--){
        if(res.empty() ||
           (len[k]==len[lastindex]+1 && arr[lastindex]<res.top())){
            res.push(arr[lastindex]);
            k=lastindex;
        }
    }

    while(res.size()>1){
        cout<<res.top()<<" ";
        res.pop();
    }

    cout<<res.top()<<endl;
    return 0;
}
