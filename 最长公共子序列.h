/*
给定两个字符串str1和str2，输出连个字符串的最长公共子序列。
如果最长公共子序列为空，则输出-1。
输入
1A2C3D4B56
B1D23CA45B6A

输出
123456

思路：经典的dp题
1.dp[i][j]表示str1[0..i] 与str2[0..j]之间的最长子序列长度
2.状态转移方程 str1[i]!=str2[j] 时，dp[i][j]=max(dp[i-1][j],dp[i][j-1])
              str1[i]==str2[j]时，dp[i][j]=max(dp[i-1][j],dp[i][j-1],dp[i][j-1]+1)
3.根据这个状态矩阵去找对应的字符串序列，dp[i][j]=dp[i-1][j-1]+1的地方说明str1[i]=str2[j]

*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    string str1;
    string str2;
    cin>>str1>>str2;

    int n=str1.size();
    int m=str2.size();
    if(n==0 || m==0) {
        cout<<"-1"<<endl;
        return 0;
    }

    vector<vector<int>> dp(n,vector<int>(m,0));

    dp[0][0]=str1[0]==str2[0]? 1:0;
    for(int i=1;i<m;++i){
        dp[0][i]=str1[0]==str2[i]? 1:dp[0][i-1];
    }

    for(int i=1;i<n;++i){
        dp[i][0]= str1[i]==str2[0]? 1:dp[i-1][0];
    }

    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            if(str1[i]==str2[j]){
                dp[i][j]=max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1]));
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    int len=dp[n-1][m-1];
    string res(len,'0');
    int index=len-1;
    n--;
    m--;
    while(index>=0){
        if(n>0 && dp[n][m]==dp[n-1][m]){
            n--;
        }else if(m>0 && dp[n][m]==dp[n][m-1]){
            m--;
        }else{
            res[index--]=str1[n];
            n--;
            m--;
        }
    }

    cout<<res<<endl;

    return 0;
}
