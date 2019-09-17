#include <bits/stdc++.h>
using namespace std;

/*
 * Leetcode 91 medium
一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

例子：
输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。

思路：可以用dp的方法来做
1.用dp[0..n-1]分别表示以s[0..n-1]结尾的子字符串的可以解码的方法数目
2.根据s[i],s[i-1]来判断当前dp[i]的数值：
    1)s[i]=='0' && (s[i-1]>='3' || s[i-1]=='0')
      // 0前面必须是1或者2,否则就是错误类型
    2)s[i]=='0' && (s[i-1]=='1' || s[i-1]=='2')
      dp[i]=dp[i-1]=dp[i-2],要判断dp[i-2]是否数组越界
    3)s[i]!='0' && (s[i-1]=='1' || (s[i-1]=='2'&& s[i]<='6'))
      可以组成类似于 5|12，5|1|2两种情况，但也要注意dp[i-2]是否越界
      状态更新方程：dp[i]=dp[i-1]+dp[i-2]
    4)其余的情况下567==>5|6|7：
      状态更新方程:dp[i]=dp[i-1]
 */

class Solution {
public:
    int numDecodings(string s) {
        int len=s.size();
        if(len==0) return 0;
        if(s[0]=='0') return 0;

        vector<int>dp(len,0);
        dp[0]=1;
        for(int i=1;i<len;++i){
            if(s[i]=='0'){
                if(s[i-1]>='3' || s[i-1]=='0'){
                    return 0;
                }else{
                    dp[i]=dp[i-1]=(i-2<0?1:dp[i-2]);
                }
            }else if((s[i-1]=='1') || (s[i-1]=='2'&& s[i]<='6')){
                dp[i]=dp[i-1]+(i-2<0?1:dp[i-2]);
            }else{
                dp[i]=dp[i-1];
            }
        }
        return dp[len-1];
    }
};
