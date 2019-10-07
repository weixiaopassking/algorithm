#include <solution.h>
#include <bits/stdc++.h>
using namespace std;
/*
有一些数的素因子只有3、5、7，请设计一个算法，找出其中的第k个数。
给定一个数int k，请返回第k个数。

输入：3
返回：7


思路：
用一个数组去存储结果，
用3个下标存储上一次乘的对象，每次从3个数中选取一个最小的加到数组后面
然后更新下标，连续进行k次。
*/

class KthNumber {
public:
    int getmin(int num1,int num2,int num3){
        return min(min(num1,num2),num3);
    }

    int findKth(int k) {
        // write code here
        vector<int> dp={1};
        int a=0,b=0,c=0;
        for(int i=0;i<k;++i){
            int mul3=dp[a]*3;
            int mul5=dp[b]*5;
            int mul7=dp[c]*7;
            int small=getmin(mul3,mul5,mul7);
            dp.push_back(small);
            if(mul3<=small)
                ++a;
            if(mul5<=small)
                ++b;
            if(mul7<=small)
                ++c;
        }
        return dp[k];
    }
};
