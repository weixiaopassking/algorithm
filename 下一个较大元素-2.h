/*
请找出数组中每个元素的后面比它大的最小的元素，若不存在则为-1。
给定一个int数组A及数组的大小n，请返回每个元素所求的值组成的数组。保证A中元素为正整数

测试样例：
[11,13,10,5,12,21,3],7
[12,21,12,12,21,-1,-1]

思路：
一个主栈，用来从小到大存放已经遍历过的数字
辅助栈用来保存主栈中比A[i]小的数据，下次A[i]塞进去后，再把辅助栈中的数据在塞进去。
 */

class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        int len=A.size();
        vector<int> ret(A.size(),-1);
        stack<int> stk;
        stack<int> cor;
        stk.push(-1);
        for(int i=len-1;i>=0;--i){
            int cur=stk.top();
            while(cur!=-1 && A[i]>=cur){
                cor.push(cur);
                stk.pop();
                cur=stk.top();
            }
            ret[i]=cur;
            stk.push(A[i]);
            while(!cor.empty()){
                stk.push(cor.top());
                cor.pop();
            }
        }
        return ret;
    }
};
