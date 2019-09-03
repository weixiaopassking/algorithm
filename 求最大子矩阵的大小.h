/*
给定一个整型矩阵 map，其中的值只有 0 和 1 两种，
求其中全是 1 的所有矩形区域中，最大的矩形区域里 1 的数量。

输入描述:
第一行输入两个整数 n 和 m，代表 n*m 的矩阵
接下来输入一个 n*m 的矩阵
输出描述:
输出其中全是 1 的所有矩形区域中，最大的矩形区域里 1 的数量。

输入
1 4
1 1 1 0
输出
3

思路：
1.考虑以某一行为底，更新“大楼”的高度
2.用栈来计算以某一栋楼高为高度，向两边扩展，能得到的最大面积
3.得出最大面积
时间复杂度O(n*m)，空间复杂度O(m);
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int m;
    cin>>n>>m;
    int res=0;
    vector<vector<int>> map(n,vector<int>(m,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>map[i][j];
        }
    }

    vector<int> height(m,0);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            height[j]= map[i][j]==1? height[j]+1: 0;
        }

        stack<int> st;
        for(int k=0;k<m;++k){
            while(!st.empty() && height[st.top()]>=height[k]){
                int top=st.top();st.pop();
                int curtop=st.empty()? -1:st.top();
                int curarea=height[top]*(k-1-curtop);
                res=max(res,curarea);
            }
            st.push(k);
        }

        while(!st.empty()){
            int top=st.top();st.pop();
            int curtop=st.empty()?-1:st.top();
            int curarea=height[top]*(top-curtop);
            res=max(res,curarea);
        }

    }

    cout<<res<<endl;
    return 0;

}

