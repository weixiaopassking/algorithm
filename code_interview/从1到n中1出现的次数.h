#include <bits/stdc++.h>
using namespace std;

/*
从1 到 n 中1出现的次数
 */

class Solution {
public:
    int powerof10(int n){
        int ret=1;
        while(n>0){
            ret*=10;
            n--;
        }
        return ret;
    }

    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<=0) return 0;
        string strn=to_string(n);
        if(strn.size()==1) return 1;

        if(strn[0]=='1'){
            int rest=n-powerof10(strn.size()-1)+1;//首位为1的个数，位数和n相同,+1因为要算入100...00的情况
            int onebit=(strn.size()-1)*powerof10(strn.size()-2);//除了首位外，其他位上为1的个数
            return rest+NumberOf1Between1AndN_Solution(rest)+onebit;
        }else{
            int rest=n-(strn[0]-'0')*powerof10(strn.size()-1);
            int onebit=(strn.size()-1)*powerof10(strn.size()-2)*(strn[0]-'0');
            return powerof10(strn.size()-1)+NumberOf1Between1AndN_Solution(rest)+onebit;
        }
    }
};
