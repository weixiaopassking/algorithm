#include <bits/stdc++.h>
using namespace std;

/*
现有一些随机生成的数字要将其依次传入，对于每次传入一个数字后，
算出当前所有传入数字的中位数。
(若传入了偶数个数字则令中位数为第n/2小的数字，n为已传入数字个数)。

[1,2,3,4,5,6],6

返回：[1,1,2,2,3,3]

 */

class Middle {
public:
    vector<int> getMiddle(vector<int> A, int n) {
        vector<int> ret;
        if(n==0) return ret;
        if(n==1) {ret.push_back(A[0]); return ret;}
        ret.push_back(A[0]);

        priority_queue<int,vector<int>,std::greater<int> > small;
        priority_queue<int,vector<int>,std::less<int> > big;
        if(A[1]>A[0]){
            ret.push_back(A[0]);
            small.push(A[1]);
            big.push(A[0]);
        }else{
            ret.push_back(A[1]);
            small.push(A[0]);
            big.push(A[1]);
        }

        for(int i=2;i<n;++i){
            if(A[i]>small.top()){
                small.push(A[i]);
            }else{
                big.push(A[i]);
            }

            while(small.size()>big.size()){
                big.push(small.top());
                small.pop();
            }
            if(small.size()+1<big.size()){
                small.push(big.top());
                big.pop();
            }
            ret.push_back(big.top());
        }

        return ret;
    }
};
