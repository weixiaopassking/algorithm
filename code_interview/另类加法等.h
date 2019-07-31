#include <solution.h>
#include <bits/stdc++.h>
using namespace std;

/*
另类加法
编写一个函数，将两个数字相加。不得使用+或其他算数运算符。
给定两个int A和B。请返回A＋B的值

输入：1,2
返回：3

思想：
用位操作计算
*/

class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        int add=A&B;
        int ret=A^B;
        while(add){
            int tmp=ret^(add<<1);
            add=ret&(add<<1);
            ret=tmp;
        }
        return ret;
    }
};




/*
另类交换

请编写一个函数，函数内不使用任何临时变量，直接交换两个数的值。
给定一个int数组AB，其第零个元素和第一个元素为待交换的值，请返回交换后的数组。

测试样例：
[1,2]
返回：[2,1]

*/

class Exchange {
public:
    vector<int> exchangeAB(vector<int> AB) {
        AB[0]=AB[0]+AB[1];
        AB[1]=AB[0]-AB[1];
        AB[0]=AB[0]-AB[1];
        return AB;
    }
};

/*
另类求最大值，无判断求max。

找出两个数字中最大的那个。条件是不得使用if-else等比较和判断运算符。
给定两个int a和b，请返回较大的一个数。若两数相同则返回任意一个。
测试样例：
1，2
返回：2

思路：
使用位操作
 */
class Max {
public:
    int getMax(int a, int b) {
        // write code here
        b=a-b;
        a=a-(b&(b>>31));
        return a;
    }
};
