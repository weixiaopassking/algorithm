#include <bits/stdc++.h>
using namespace std;

/*
leetcode 322. 零钱兑换
给定不同面额的硬币 coins 和一个总金额 amount。
编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:
输入: coins = [1, 2, 5], amount = 11
输出: 3
解释: 11 = 5 + 5 + 1

示例 2:
输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。

*/


// 做法1(复杂度低)：
// 把所有的钱能够凑成的总数作为状态i，dp[i]表示凑成i金额的钱币的数目
// 内循环为给的不同钱币，新增一种不同面值的钱，就去更新大于该币种的所有状态
int main(){
    int n,aim;
    cin>>n>>aim;
    vector<int> data(n,0);
    for(int i=0;i<n;i++){
        cin>>data[i];
    }

    vector<int> dp(aim+1,aim+1);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=data[i];j<=aim;j++){
            dp[j]=min(dp[j],dp[j-data[i]]+1);
        }
    }

    if(dp[aim]==aim+1){
        cout<<"-1"<<endl;
    }else{
        cout<<dp[aim]<<endl;
    }

    return 0;
}


// 做法2(复杂度会高一些)：
// 把所有的钱能够凑成的总数作为状态i，dp[i]表示凑成i金额的钱币的数目
// 状态i作为外循环，内循环是不同的钱币，一次内循环确定状态i最少的钱币数，直到amount
class Solution {
public:
    vector<int> dp;
    int coinChange(vector<int>& coins, int amount) {
        int clen=coins.size();
        if(amount==0) return 0;
        if(clen==0 ) return -1;

        dp=vector<int>(amount+1,0);

        for(int i=1;i<=amount;++i){
            dp[i]=INT_MAX;
            for(int j=0;j<clen;++j){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }

        return dp[amount]==INT_MAX? -1:dp[amount];

    }

};
