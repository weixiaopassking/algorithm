#include <bits/stdc++.h>
using namespace std;

/*
有数量不限的硬币，币值为25分、10分、5分和1分，请编写代码计算n分有几种表示法。
给定一个int n，请返回n分有几种表示法。
保证n小于等于100000，为了防止溢出，
请将答案Mod 1000000007。

测试样例：
6
返回：2

思路：
以币值作为行，钱的总额作为列，
   0    1   2   ...   7   8   9   10   11   ...
1  1    1   1   ...   1   1   1   1     1
5  1    1   1   ...   2   2   2   3     3
10              ...
25              ...

总结来说就是：
不使用新面值的方法数加至少使用一枚新面值的方法数。
dp[j]=dp[j]+dp[j-coin[i]]
 总的 =旧的 +新的
*/

class Coins {
public:
    int countWays(int n) {
        // write code here
        vector<int> dp(n+1,0);
        vector<int> coin={1,5,10,25};
        dp[0]=1;
        for(int i=0;i<coin.size();++i){
            for(int j=coin[i];j<=n;++j){
                dp[j]=(dp[j]+dp[j-coin[i]])%1000000007;
            }
        }

        return dp[n];
    }
};

