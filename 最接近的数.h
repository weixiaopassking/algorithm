#include <bits/stdc++.h>
using namespace std;

/*
有一个正整数，请找出其二进制表示中1的个数相同、且大小最接近的那两个数。
(一个略大，一个略小)
给定正整数int x，请返回一个vector，代表所求的两个数（小的在前）。
保证答案存在。

输入：2
返回：[1,4]

思路：
简单的方法是
*/

// 这种方法比较复杂
// 大的数：找到右侧第一个‘01’对，然后互换，然后将右侧所有的0放在最左边，所有的1放在最右边
// 小的数：找到右侧第一个'10'对，然后互换，然后将右侧所有的1放在最左边，所有的0放在最右边
class CloseNumber {
public:
    vector<int> getCloseNumber(int x) {
        // write code here
        int small=x;
        string s;
        int left10=-1;  // "10"中0的位置
        int right01=-1; // "01"中1的位置
        int bitcnt=0;
        while(small!=0){
            if(small&1){
                s='1'+s;
            }else{
                s='0'+s;
            }
            small/=2;
            bitcnt++;
        }

        for(int i=s.size()-1;i>0;--i){
            if( right01==-1 && s[i]=='1' && s[i-1]=='0'){
                right01=s.size()-1-i;
            }
            if( left10==-1 && s[i]=='0' && s[i-1]=='1'){
                left10=s.size()-1-i;
            }
        }

        vector<int> ret(2,x);
        if(right01==-1){
            ret[1]=x<<1;
        }else{
            ret[1]=x+(1<<right01);
            for(int i=right01-1,j=0;j<i;++j,--i){
                while(i>0 && s[s.size()-1-i]=='0') --i;
                while(j<s.size() && s[s.size()-1-j]=='1') ++j;
                if(j<i){
                    ret[1]=ret[1]-(1<<i)+(1<<j);
                }
            }
        }

        ret[0]=x-(1<<left10);
        for(int i=left10-1,j=0;j<i;++j,--i){
            while(i>0 && s[s.size()-1-i]=='1') --i;
            while(j<s.size() && s[s.size()-1-j]=='0') ++j;
            if(j<i) {
                ret[0]=ret[0]+(1<<i)-(1<<j);
            }
        }
        return ret;
    }
};


int main(){
    CloseNumber s;
    vector<int> ret=s.getCloseNumber(96502);
    cout<<ret[0]<<endl<<ret[1]<<endl;
    return 0;
}


/*
96502
[96501,96505]
*/
