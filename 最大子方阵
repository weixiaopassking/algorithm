#include <bits/stdc++.h>
using namespace std;

/*
有一个方阵，其中每个单元(像素)非黑即白(非0即1)，请设计一个高效算法，找到四条边颜色相同的最大子方阵。
给定一个01方阵mat，同时给定方阵的边长n，请返回最大子方阵的边长。保证方阵边长小于等于100。

测试样例：
[[1,1,1],[1,0,1],[1,1,1]],3
返回：3

思路：


*/


class SubMatrix {
public:
    int maxSubMatrix(vector<vector<int> > mat, int n) {
        vector<vector<int> > above(n,vector<int>(n,1));
        vector<vector<int> > down(n,vector<int>(n,1));
        vector<vector<int> > left(n,vector<int>(n,1));
        vector<vector<int> > right(n,vector<int>(n,1));

        for(int i=1;i<n;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==mat[i-1][j]){
                    above[i][j]=above[i-1][j]+1;
                }
            }
        }

        for(int i=n-2;i>=0;--i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==mat[i+1][j]){
                    down[i][j]=down[i+1][j]+1;
                }
            }
        }

        for(int j=1;j<n;++j){
            for(int i=0;i<n;++i){
                if(mat[i][j]==mat[i][j-1]){
                    left[i][j]=left[i][j-1]+1;
                }
            }
        }

        for(int j=n-2;j>=0;--j){
            for(int i=0;i<n;++i){
                if(mat[i][j]==mat[i][j+1]){
                    right[i][j]=right[i][j+1]+1;
                }
            }
        }

        for(int ret=n;ret>0;--ret){
            for(int i=0;i<n && i+ret-1<n;++i){
                for(int j=0;j<n && j+ret-1<n;++j){
                    if(down[i][j]>=ret && right[i][j]>=ret
                      && above[i+ret-1][j+ret-1]>=ret
                      && left[i+ret-1][j+ret-1]>=ret){
                        return ret;
                    }
                }
            }
        }
        return 1;
    }
};
