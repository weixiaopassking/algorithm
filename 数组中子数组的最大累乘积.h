#include<bits/stdc++.h>
using namespace std;

/*
给定一个double类型的数组arr，其中的元素可正、可负、可0，返回子数组累乘的最大乘积。
例如，arr=[-2.5, 4, 0, 3, 0.5, 8, -1]，
子数组[3, 0.5, 8]累乘可以获得最大的乘积12，所以返回12

时间复杂度为O(n)，空间复杂度为O(1)

思路：dp算法
1.假设最后的答案数组以arr[i]结尾，那么arr[i]结尾的这个数组乘积最大值有三种可能来源：
   1)前面的最大值maxnum * arr[i]
   2)前面的最小值minnum * arr[i]
   3)就只有arr[i]
2.遍历到arr[i]时，更新maxnum=max(minend,max(maxend,num));
                    minnum=min(minend,min(maxend,num));
3.更新res=max(res,maxnum);

 */


int main(){
    int n;
    cin>>n;
    double res;
    cin>>res;
    double maxnum=res;
    double minnum=res;
    double num;
    for(int i=0;i<n-1;++i){
        cin>>num;
        double maxend=maxnum*num;
        double minend=minnum*num;
        maxnum=max(minend,max(maxend,num));
        minnum=min(minend,min(maxend,num));
        res=max(res,maxnum);
    }

    printf("%.2f\n",res);
    return 0;
}
