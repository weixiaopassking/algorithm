#include <bits/stdc++.h>
using namespace std;

/*
有n个人站成一列,第一个人编号为1。
然后从头开始报数，第一轮依次报1，2，1，2...然后报到2的人出局。
再从上一轮最后一个报数的人开始依次报1，2，3，1，2，3...报到2，3的人出局。
最后剩下以后一个人。求这个人的编号。

给定一个int n，代表游戏的人数。请返回最后一个人的编号

测试样例：
5
返回：5

思路：
* 从0开始编号
* 递归
* 看注释
*/

class Joseph {
public:
    int helper(int n,int m){
        if(n<=m) return 0;

         //计算剩余人数
        int left=(n-1)/m+1;
        //先把剩余人数看做从最后一个开始的0到left-1编号，递归返回后寻找与原始编号的关系
        return (helper(left,m+1)+left-1)%left*m;
    }

    int getResult(int n) {
        //换一种编号策略，从0开始，这样方便计算，所以返回结果时加1
        return helper(n,2)+1;
    }
};
