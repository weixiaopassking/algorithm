#include <bits/stdc++.h>
using namespace std;

/*
leetcode 547：朋友圈
班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。
如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。
给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。
如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。
你必须输出所有学生中的已知的朋友圈总数。

示例：
输入:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。

思路：基本的并查集操作
1.对图的邻接矩阵进行检查,如果两个人是朋友，则关联这两个朋友圈
2.关联这两个朋友圈主要是关联这两个集合的根(circle())
3.找集合的根的过程中更新每个人自己的根(find())
4.找到最后有多少个根就是有多少个朋友圈
*/

class Solution {
public:
    vector<int>un;
    void circle(int i,int j){
        if(i==j) return;
        int findi=find(i);
        int findj=find(j);
        if(findi==findj) return;

        int minval=min(findi,findj);
        // ！！！格外注意这里是findi和findj,而不是i与j
        un[findi]=minval;
        un[findj]=minval;
    }

    int find(int i){
        if(un[i]==i) return i;
        un[i]=find(un[i]);
        return un[i];
    }

    int findCircleNum(vector<vector<int>>& M) {
        int len=M.size();
        un.resize(len);
        for(int i=0;i<len;++i){
            un[i]=i;
        }

        for(int i=0;i<len;++i){
            for(int j=i+1;j<len;++j){
                if(M[i][j]==1){
                    circle(i,j);
                }
            }
        }

        unordered_set<int> st;
        for(int val:un){
            // 找到最后有多少个根就是有多少个朋友圈
            int x=find(val);
            st.insert(x);
        }

        return st.size();
    }
};
