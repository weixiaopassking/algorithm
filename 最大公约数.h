#include <bits/stdc++.h>
using namespace std;

/*
辗转相除法求a,b的最大公约数：
gcd(a,b)=gcd(b,a%b);

求m和n的最大公约数。
1.k,r分别是a除以b的商和余数，即a=kb+r。
2.c=gcd(a,b)表示a和b的最大公约数。
求证：gcd(b,r)==gcd(a,b)=c

1.因为c=gcd(a,b),所以a=mc,b=nc,m和n互质==>考虑(m-kn)>0时，(m-kn)和n互质
2.因为a=kb+r，所以r=a-kb=mc-knc=(m-kn)c
3.因为m和n互质，r=(m-kn)c和b=nc因为(m-kn)和n互质，所以最大公约数为c。

*/

// 辗转相除法用递归实现
int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}


// 用循坏实现
int gcd(int a,int b){
    if(a==b) return b;
    if(a<b) swap(a,b);
    while(a%b){
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    return b;
}
