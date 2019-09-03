
#include <bits/stdc++.h>
using namespace std;


// 只用递归逆序一个栈
// 思路：
// 1.取出栈底的那个元素，然后将剩下的那部分逆序（myfun递归），再将取出的栈底元素放在栈顶
// 2.取出栈底部元素：getstbottom
int getstbottom(stack<int>& st){
    int cur=st.top();st.pop();
    if(st.empty()){
        return cur;
    }

    int bt=getstbottom(st);
    st.push(cur);
    return bt;
}


void myfun(stack<int>& st){
   if(st.empty()) return;
   int bottom=getstbottom(st);
   myfun(st);
   st.push(bottom);

}


int main ()
{
    stack<int> st;
    st.push(1);;
    st.push(2);;
    st.push(3);
    st.push(4);

    stack<int> cur(st);
    while(!cur.empty()){
        cout<<cur.top()<<endl;
        cur.pop();
    }

    cout<<endl;
    myfun(st);

    cur=st;
    while(!cur.empty()){
        cout<<cur.top()<<endl;
        cur.pop();
    }

    return 0;
}


