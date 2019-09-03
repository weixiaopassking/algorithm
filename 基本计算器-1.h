#include <bits/stdc++.h>
using namespace  std;

/*
leetcode 224. 基本计算器 hard
实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。

输入: "(1+(4+5+2)-3)+(6+8)"
输出: 23
*/

/*
思路：
res记录当前结果，sign记录当前符号，利用栈来实现括号的优先计算
如果是左括号,那么将当前res、sign的值依次压入栈中，然后将res重置为0、sign重置为1准备计算括号中的值；
如果是右括号，说明res中当前存的是括号中计算的结果，那么弹出栈顶的sign，res*=sign，
思想就是用栈来保存前一个操作以及做操作数，括号结束得到右操作数，然后计算结果
继续弹出栈顶存储的之前的res，res+=res
*/

class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;

        stack<int> stk;
        int sign=1;
        int res=0;

        for(int i=0;i<s.size();++i){
            char c=s[i];

            if(c==' '){
                continue;
            }

            if(c>='0' && c<='9'){
                int num=0;
                while(i<s.size() && s[i]>='0' && s[i]<='9'){
                    num=num*10-'0'+s[i];
                    i++;
                }
                i--;
                res=res+sign*num;
            }else if(c=='+'){
                sign=1;
            }else if(c=='-'){
                sign=-1;
            }else if(c=='('){
                stk.push(res);
                stk.push(sign);
                res=0;
                sign=1;
            }else if(c==')'){
                res=res*stk.top();stk.pop();
                res=res+stk.top();stk.pop();
            }
        }
        return res;
    }
};

// 利用两个栈的做法，一个栈存数据，
// 一个栈存当前去括号后应该变的符号
// 主要思想都是把所有数存下来，然后全部加和的方式
class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;

        int num=0;
        stack<int> stk;
        stack<int> st;
        st.push(1);
        char op='+';

        for(int i=0;i<=s.size();++i){
            char c;
            if(i<s.size())  c=s[i];
            else c='+';

            if(c==' '){
                continue;
            }

            if(c>='0' && c<='9'){
                num=num*10-'0'+c;
                continue;
            }else if(c=='('){
                if(op=='-') {
                    st.push(-1*st.top());
                    op='+';
                    continue;
                }
                else{
                    st.push(st.top());
                    continue;
                }
            }else if(op=='+'){
                if(!st.empty()) num=num*st.top();
                stk.push(num);
                num=0;
                op=c;
                if(c==')') {
                    st.pop();
                    op='+';
                }
            }else if(op=='-'){
                if(!st.empty()) num=num*st.top();
                stk.push(-num);
                num=0;
                op=c;
                if(c==')') {
                    st.pop();
                    op='+';
                }
            }
        }

        int ret=0;
        while(!stk.empty()){
            ret+=stk.top();stk.pop();
        }
        return ret;
    }
};

int main(){
    Solution s;
    cout<<s.calculate("2-(5-6)")<<endl;
    return 0;
}
