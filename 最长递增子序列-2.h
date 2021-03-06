#include <bits/stdc++.h>
using namespace std;

/*
pair<int,int>的最长递增子序列；
后面一个pair中的两个数要分别比前面一个pair的两个数大
题目中给出的pair是可以重新排序的，顺序不固定

测试样例：
[[1,2],[3,4],[5,6],[7,8]],4
返回：4

思路：
1.先对整个输入排序，第一关键字pair.first,第二关键字pair.second
2.按照最长vector<int>的递增子序列的方法求最长递增子序列
 （可以用普通的dp算法，也可以用dp+二分查找的方法做，但是pair的二分查找麻烦一些）
3.普通的dp方法：dp[i]表示以actor[i]为最后一个数的最长序列个数
  状态转移：在j<i的情况下，如果actor[i]可以放在actor[j]后，
           那么dp[i]取max(dp[i],dp[j]+1)

 */

class Stack {
public:
    int getHeight(vector<vector<int> > actors, int n) {
        if(actors.empty()) return 0;
        sort(actors.begin(),actors.end(),[](vector<int> &l,vector<int>& r){
            return l[0]<r[0] || (l[0]==r[0] && l[1]<r[1]);
        });

        vector<int> dp(n,1);
        int ret=1;
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(actors[j][0]>=actors[i][0]) continue;
                if(actors[j][1]<actors[i][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ret=max(ret,dp[i]);
        }

        return ret;
    }
};



// 以下是用pair的二分查找实现的方法
// 不断扩大dp数组的大小
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2,0));
    for(int i=0;i<n;++i){
        cin>>arr[i][0]>>arr[i][1];
    }

    // ！！！下面l[0]==r[0] && l[1]>r[1]这一步很关键，从大到小
    sort(arr.begin(),arr.end(),[](vector<int> l,vector<int> r){
        bool ret=(l[0]<r[0]) || (l[0]==r[0] && l[1]>r[1]);
        return ret;
    });

    vector<vector<int>> dp(1,arr[0]);

    for(int i=1;i<n;++i){
        int low=0;
        int high=dp.size();
        while(low<high){
            int mid=low+(high-low)/2;
            if(dp[mid][0]<=arr[i][0] && dp[mid][1]<=arr[i][1])
                low=mid+1;
            else
                high=mid;
        }

        if(high<dp.size())  dp[high]=arr[i];
        else dp.push_back(arr[i]);
    }

    cout<<dp.size()<<endl;

    return 0;
}

