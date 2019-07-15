#include "solution.h"

/*
找矩阵中的一个子矩阵，使他每个元素加起来和最大，矩阵中的数值有正有负。

核心思想：
（以第一行最为开始）先求第一行的最大和，然后将第二行数据加到第一行，
再求此时的最大值，然后再将下一行加上去，求最大值......最终得到第一列到最后一列的最大值；
还要计算第二行到最后一行的最大和，第三行到最后一行的最大和；
*/


#include <bits/stdc++.h>

using namespace std;

class SubMatrix {
public:
    int sumofrow(vector<int>& row,int n){
        vector<int> dp(n,0);
        dp[0]=row[0];
        int ret=row[0];
        for(int i=1;i<n;++i){
            if(dp[i-1]>0){
                dp[i]=dp[i-1]+row[i];
            }else{
                dp[i]=row[i];
            }
            ret=max(ret,dp[i]);
        }
        return ret;
    }

    int sumOfSubMatrix(vector<vector<int> > mat, int n) {
        int ret=INT_MIN;

        for(int i=0;i<n;++i){
            vector<int> row(n,0);
            for(int j=i;j<n;++j){
                for(int k=0;k<n;++k){
                    row[k]+=mat[j][k];
                }
                ret=max(ret,sumofrow(row,n));
            }
        }

        return ret;
    }
};


int main(){
    SubMatrix s;
    vector<vector<int> > v={{-10,1},{-15,24}};
    cout<<s.sumOfSubMatrix(v,2);
    return 0;
}
