#include <bits/stdc++.h>
using namespace  std;

class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;

        int num=0;
        stack<int> stk;
        stack<int> st;
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
                if(op=='+'){
                    st.push(1);
                    continue;
                }
                else if(op=='-') {
                    st.push(-1);
                    flag=!flag;
                    op='+';
                    continue;
                }
            }else if( c==')'){
                st.pop();
            }else if(op=='+'){
                if(!st.empty()) num=num*st.top();
                stk.push(num);
            }else if(op=='-'){
                if(!st.empty()) num=num*st.top();
                stk.push(-num);
            }
            num=0;
            op=c;
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
    cout<<s.calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
    return 0;
}
