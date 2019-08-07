#include <bits/stdc++.h>
using namespace std;


/*
leetcode 227 基本计算器  medium
实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。
整数除法仅保留整数部分。

示例：
输入: "3+2*2"
输出: 7

思路：
用一个栈来保存每一个小部分的计算结果，最后求和。
op是上一次的操作符号，c是本次的操作符号，num是最近一个数字。
例如，当c=‘+’时，op是预定的操作‘+’，这时候把当前的num放入栈中。
当c=‘*’时，op是上一次的‘+’，这时把num=2放入栈中；
当最后一次，i==len了，op='*',这时把栈顶的数取出来和当前的num==2相乘，再放回去。

最后整个栈求和。
*/

class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;

        int len=s.size();
        stack<int> stk;
        char op='+';
        int num=0;
        for(int i=0;i<=len;++i){
            char c;
            if(i<len) c=s[i];
            else c='+';

            if(c==' '){
                continue;
            }

            if(c>='0' && c<='9'){
                num=num*10-'0'+c;
                continue;
            }else if(op=='*'){
                int top=stk.top();stk.pop();
                top=top*num;
                stk.push(top);
            }else if(op=='/'){
                int top=stk.top();stk.pop();
                top=top/num;
                stk.push(top);
            }else if(op=='+'){
                stk.push(num);
            }else if(op=='-'){
                num=-num;
                stk.push(num);
            }
            op=c;
            num=0;
        }

        int ret=0;
        while(!stk.empty()){
            int cur=stk.top();stk.pop();
            ret=ret+cur;
        }
        return ret;
    }
};
