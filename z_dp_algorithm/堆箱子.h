#include <bits/stdc++.h>
using namespace std;


/*
有一堆箱子，每个箱子宽为wi，长为di，高为hi，
现在需要将箱子都堆起来,上面的箱子的宽度和长度必须小于下面的箱子。
请实现一个方法，求出能堆出的最高的高度，这里的高度即堆起来的所有箱子的高度之和。
给定三个int数组w,l,h，分别表示每个箱子宽、长和高，同时给定箱子的数目n。
请返回能堆成的最高的高度。保证n小于等于500。

测试样例：
[1,1,1],[1,1,1],[1,1,1]
返回：1

思路：
dp算法,最长递增子序列的变体。
1.箱子从按宽度从低到高排列，然后对每个箱子box[i],它能叠起来的最大高度是dp[i];
2.如果在它前面有箱子j比它小，那么它的高度可以是dp[i]=max(dp[i],dp[j]+box[i].h)
3.每次保存最大高度作为返回值 ret=max(ret,dp[i]);
 */
class Box {
public:
    int getHeight(vector<int> w, vector<int> l, vector<int> h, int n) {
        // write code here
        vector<vector<int> > box;
        for(int i=0;i<n;++i){
            vector<int> ele={w[i],l[i],h[i]};
            box.push_back(ele);
        }

        sort(box.begin(),box.end(),[](vector<int> &l,vector<int>& r){
            return (l[0]<r[0] || (l[0]==r[0] && l[1]<r[1]));
        });

        vector<int> dp(n,0);
        dp[0]=box[0][2];

        int ret=dp[0];
        for(int i=1;i<n;++i){
            dp[i]=box[i][2];
            for(int j=0;j<i;++j){
                if(box[i][0]>box[j][0] && box[i][1]>box[j][1]){
                    dp[i]=max(dp[j]+box[i][2],dp[i]);
                }
            }
            ret=max(ret,dp[i]);
        }
        return ret;
    }
};
