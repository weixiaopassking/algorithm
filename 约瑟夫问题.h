#include <bits/stdc++.h>
using namespace std;

/*
约瑟夫问题是一个非常著名的趣题，
n个人围成一圈，编号【1~n】(不是0~n-1)，
从第1个人开始报数，数到m的人出局，然后从头开始报数。
求最后一个出局的人的编号。
保证n和m小于等于1000。

测试样例：
5 3
返回：4

思路：
【编号从0~n-1与1~n的区别：每次取余数后需要从0开始或者从1开始】
【但是从1开始实现比较复杂，所以直接从0开始，0->1,1->2,实现对应关系】
主要就是要找到递推公式，
如果人的编号从0~n-1的话：是剑指offer的原题page202
f(n,m)表示这个函数的返回值,
n=1时，f(1,m)=0
n>1时，f(n,m)=[f(n-1,m)+m]%n
因为是按照从0~n-1实现的，所以最后需要加1。
*/

class Joseph {
public:
    int getResult(int n, int m) {
        if(n<=0 || m<=0) return 0;
        int cur=0;
        for(int i=2;i<=n;++i){
            cur=(cur+m)%(i);
        }
        return cur+1;
    }
};
