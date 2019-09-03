/*
有一个NxM的整数矩阵，矩阵的行和列都是从小到大有序的。查找矩阵中元素x的位置。
给定一个int有序矩阵mat，同时给定矩阵的大小n和m以及需要查找的元素x，
请返回一个二元数组，代表该元素的行号和列号(均从零开始)。
保证元素互异。

测试样例：
[[1,2,3],[4,5,6]],2,3,6
返回：[1,2]

思路：
剑指offer原题，从右上角或者从左下角开始查找

 */
#include <bits/stdc++.h>
using namespace std;


class Finder {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
        // write code here
        int row=0;
        int col=m-1;
        vector<int> ret(2,-1);

        while(col>=0 && row<n){
            if(mat[row][col]==x){
                ret[0]=row;
                ret[1]=col;
                return ret;
            }else if(mat[row][col]<x){
                row++;
            }else{
                col--;
            }
        }
        return ret;
    }
};
