#include <bits/stdc++.h>
using namespace std;

/*
输出0到n(包括n)中数字2出现了几次
 */

class Count2 {
public:
    int po(int x){
        int ret=1;
        while(x!=0){
            ret=ret*10;
            x--;
        }
        return ret;
    }

    int countNumberOf2s(int n) {
        // write code here
        if(n<2) return 0;
        if(n<10) return 1;

        int x=n;
        int bitcnt=0;
        while(x!=0){
            x=x/10;
            bitcnt++;
        }

        int onezero=1;
        for(int i=0;i<bitcnt-1;++i){
            onezero=onezero*10;
        }

        int high=n/onezero;
        if(high>2) {
            int tmp=countNumberOf2s(n-onezero*high);
            // 537 ==>
            //     100    +5*10*2            +countNumberOf2s(37)
            return onezero+high*po(bitcnt-2)*(bitcnt-1)+tmp;
        }else if(high==2){
            int rest=n-2*onezero;
            int tmp=countNumberOf2s(n-onezero*high);
            // 237==>
            //       38+    2*10*2           +countNumberOf2s(37)
            return rest+1+2*po(bitcnt-2)*(bitcnt-1)+tmp;
        }else{
            int rest=n-high*onezero;
            int tmp=countNumberOf2s(n-onezero*high);
            //137
            //     1*10*2          +countNumberOf2s(37)
            return po(bitcnt-2)*(bitcnt-1)+tmp;
        }
    }
};
