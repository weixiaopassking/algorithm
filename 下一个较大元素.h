#include<bits/stdc++.h>
using namespace std;
/*
现在我们有一个int数组，请你找出数组中每个元素的下一个比它大的元素。
给定一个int数组A及数组的大小n，
请返回一个int数组，代表每个元素比他大的下一个元素,若不存在则为-1。
保证数组中元素均为正整数。

输入：[11,13,10,5,12,21,3],7
返回：[13,21,12,12,21,-1,-1]

思路：
用栈实现，从后往前往栈中压入数据：
需要压入数据的情形：
1.栈顶数据是-1（后面没数据），直接压入数组数据
2.当前的数组中的数据大于栈顶数据，栈顶数据更新为当前数据
结果队列中压入当前数据；

最后逆序结果栈并且输出。
 */

class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        stack<int> stk;
        stack<int> res;
        stk.push(-1);
        for(int i=n-1;i>=0;--i){
            int cur=stk.top();
            while(cur!=-1 && A[i]>=cur){
                stk.pop();
                cur=stk.top();
            }
            res.push(cur);
            stk.push(A[i]);
        }

        vector<int> ret;
        while(!res.empty()){
            ret.push_back(res.top());
            res.pop();
        }
        return ret;
    }
};
