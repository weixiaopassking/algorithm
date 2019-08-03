#include "solution.h"
#include <bits/stdc++.h>
using namespace std;

/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，
并且使皇后彼此之间不能相互攻击。
不能相互攻击：同一行，同一列，同一对角线上都不能有皇后


思路：
回溯法，然后确认每行每列每个对角线都只有一个皇后
helper()中的两个for循环就是在检查皇后是否符合规范
 */

class Solution {
public:
    int cnt;
    vector<int> cur;
    unordered_set<int> st;

    void helper(int n){
        for(int i=0;i<cur.size();++i){
            for(int j=i+1;j<cur.size();++j){
                if(abs(i-j)==abs(cur[i]-cur[j])){
                    return;
                }
            }
        }

        if(cur.size()==n){
            cnt++;
            return;
        }
        for(int i=0;i<n;++i){
            if(st.find(i)==st.end()){
                cur.push_back(i);
                st.insert(i);
                helper(n);
                st.erase(i);
                cur.pop_back();
            }
        }
    }

    int totalNQueens(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        cnt=0;
        helper(n);
        return cnt;
    }
};
