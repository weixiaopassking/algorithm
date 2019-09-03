#include<bits/stdc++.h>
using namespace std;

// 做法1(复杂度低)：
// 把所有的钱能够凑成的总数作为状态i，dp[i]表示凑成i金额的钱币的数目
// 内循环为给的不同钱币，新增一种不同面值的钱，就去更新大于该币种的所有状态
int main(){
    int n,aim;
    cin>>n>>aim;
    vector<int> arr(n,0);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    vector<int> dp(aim+1,INT_MAX);
    dp[0]=0;

    for(int i=0;i<n;++i){
        for(int j=arr[i];j<=aim;++j){
            if(dp[j-arr[i]]!=INT_MAX)
                dp[j]=min(dp[j],dp[j-arr[i]]+1);
        }
    }

    if(dp[aim]==INT_MAX) cout<<"-1"<<endl;
    else  cout<< dp[aim]<<endl;
    return 0;
}


// 做法2(复杂度会高一些)：
// 把所有的钱能够凑成的总数作为状态i，dp[i]表示凑成i金额的钱币的数目
// 状态i作为外循环，内循环是不同的钱币，一次内循环确定状态i最少的钱币数，直到amount
int main(){
    int n,aim;
    cin>>n>>aim;
    vector<int> arr(n,0);
    for(int i=0;i<n;++i){
        int x;cin>>x;
        arr[i]=x;
    }
    vector<int> dp(aim+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=aim;++i){
        for(int j=0;j<n;++j){
            if(arr[j]>i) continue;
            if(dp[i-arr[j]]!=INT_MAX ){
                dp[i]=min(dp[i],dp[i-arr[j]]+1);
            }
        }
    }
    if(dp[aim]==INT_MAX) cout<<"-1"<<endl;
    else  cout<< dp[aim]<<endl;
    return 0;
}

