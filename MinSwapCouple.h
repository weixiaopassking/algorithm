/*
给情侣们换座位，让他们坐在一起。求最少换几次？
如：[0,1] [7，6]是一对情侣。

Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.


Input: row = [3, 2, 0, 1]
Output: 0
Explanation: All couples are already seated side by side.
 */

// 每一对情侣是图的一个顶点，如果他们之间有位置错误的情况，就有一条边
// 最后只要计数有多少条边，就需要多少次座位交换情况

class Solution {
private:
    vector<int>p;
    int cnt;
    int find(int t){
        if(p[t]==t){
            return t;
        }
        p[t]=find(p[t]);
        return p[t];
    }

    void helper(int a,int b){
        int ta=find(a);
        int tb=find(b);
        if(ta!=tb){
            p[ta]=tb;
            cnt++;// add a new edge
        }
    }
public:

    int minSwapsCouples(vector<int>& row) {
        int len=row.size()/2;
        p.resize(len);
        cnt=0;
        for(int i=0;i<len;++i){
            p[i]=i;
        }

        for(int i=0;i<len;++i){
            int a=row[2*i]/2;
            int b=row[2*i+1]/2;
            helper(a,b);
        }
        return cnt;
    }
};
