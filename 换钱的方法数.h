
/*
给定数组arr，设数组长度为n，arr中所有的值都为正整数且不重复。
每个值代表一种面值的货币，每种面值的货币可以使用任意张，再给定一个整数aim，代表要找的钱数，
求换钱的方法数有多少种。由于方法的种数比较大，所以要求输出对10^9+7进行取模后的答案。

思路：
1.把所有的钱能够凑成的总数作为状态i，dp[i]表示凑成i金额的方法数
2.外循环是不同的货币数，
3.内循环为总金额数，总金额当前币值开始递增到aim，
4.新增一种不同面值的钱，就去更新大于该面值的总金额货币总数
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,aim;
    cin>>n>>aim;
    vector<int> arr(n,0);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    vector<int> dp(aim+1,0);
    dp[0]=1;
    for(int i=0;i<n;++i){
        for(int j=arr[i];j<=aim;++j){
            dp[j]=(dp[j]+dp[j-arr[i]])%(1000000007);
        }
    }

    cout<<dp[aim]<<endl;

    return 0;
}
