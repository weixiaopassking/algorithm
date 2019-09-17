#include <bits/stdc++.h>
using namespace std;

/*
打气球记分情况：
1)左右都有球：L*X*R
2)左边有球，右边无球：L*X
3)右边有球：X*R
4)左右都没有球：X
最后所有得分求和。

输入描述:
输出包括两行，第一行包括一个整数n（0<=n<=500），
第二行包括n个整数，代表数组arr （1<=arr[i]<=100）。
输出描述:
输出包括一个整数，代表可能获得的最大分数。

输入
3
3 2 5
输出
50
说明
2->1->3  3*2*5+3*5+5=50

思路：
1)dp[L][R]代表在区间[L,R]之间的可以打出的最大分数
2)状态转移方程，对于每个dp[L][R],
dp[L][R]=max(dp[L][R],dp[L][i-1]+arr[L-1]*arr[i]*arr[R+1]+dp[i+1][R]);
 */


int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<"0"<<endl;;
        return 0;
    }
    vector<int> arr(n+2,0);
    arr[0]=1;
    arr[n+1]=1;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }
    vector<vector<int>> dp(n+2,vector<int>(n+2,1));
    for(int i=1;i<=n;++i){
        dp[i][i]=arr[i-1]*arr[i]*arr[i+1];
    }

    for(int L=n;L>=1;--L){
        for(int R=L+1;R<=n;++R){
            int sumL=arr[L-1]*arr[L]*arr[R+1]+dp[L+1][R];
            int sumR=arr[L-1]*arr[R]*arr[R+1]+dp[L][R-1];
            dp[L][R]=max(sumL,sumR);
            for(int i=L+1;i<=R-1;++i){
                dp[L][R]=max(dp[L][R],dp[L][i-1]+arr[L-1]*arr[i]*arr[R+1]
                        +dp[i+1][R]);
            }
        }
    }

    cout<<dp[1][n]<<endl;

    return 0;
}
