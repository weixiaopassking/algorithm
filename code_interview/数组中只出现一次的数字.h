#include <bits/stdc++.h>
using namespace std;

/*
一个整型数组里除了两个数字之外，
其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。

思路：剑指offer原题
用位操作进行，0对一个数异或两次还是0，
用这个原理将所有数异或，最后结果就是出现一次的两个数的异或
然后对这两个数进行区分
 */

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<2)  return;

        int sum=0;
        for(int i=0;i<data.size();++i){
            sum=sum^data[i];
        }
        int bit=0;
        for(int i=0;i<32;++i){
            if((1<<i)&sum){
                bit=i;
                break;
            }
            if(i==31) return;
        }

        int a=0;
        int b=0;
        for(int i=0;i<data.size();++i){
            if(data[i] & (1<<bit)){
                a=a^data[i];
            }else{
                b=b^data[i];
            }
        }
        *num1=a;
        *num2=b;
    }
};
