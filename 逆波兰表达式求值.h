#include <bits/stdc++.h>
using namespace std;
/*
LeetCode 150. 逆波兰表达式求值 medium

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

示例：
输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6

思路：
用一个栈保存左右两个操作数；
遇到某个操作符时就把前面两个操作数取出来计算，计算完把结果再放回去
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int left;
        int right;
        for(int i=0;i<tokens.size();++i){
            if(tokens[i]=="+"){
                right=stk.top();stk.pop();
                left=stk.top();stk.pop();
                left=left+right;
                stk.push(left);
            } else if(tokens[i]=="-"){
                right=stk.top();stk.pop();
                left=stk.top();stk.pop();
                left=left-right;
                stk.push(left);
            }else if( tokens[i]=="*") {
                right=stk.top();stk.pop();
                left=stk.top();stk.pop();
                left=left*right;
                stk.push(left);
            }else if( tokens[i]=="/"){
                right=stk.top();stk.pop();
                left=stk.top();stk.pop();
                left=left/right;
                stk.push(left);
            }else{
                int a=atoi(tokens[i].c_str());
                stk.push(a);
            }
        }
        return stk.top();
    }
};
