/*
给定两个字符串str1和str2,输出两个字符串的最长公共子串，
如果最长公共子串为空，输出-1。

输入
1AB2345CD
12345EF
输出
2345

思路：(经典的dp问题，可以用传统的子序列方法做，但可以有更优的方法)

优化方法：
1.设置一个找到的最大长度变量len，按照对角线方法去更新len
2.找到了一个更大的len后，记录下此时是某个字符串的结尾end
3.遍历O(n*m)的时间复杂度之后，按照len和end找到最长公共子串
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1;
    string str2;
    cin>>str1>>str2;
    int n=str1.size();
    int m=str2.size();

    if(m==0 || n==0){
        cout<<"-1"<<endl;
        return 0;
    }

    int len=0;
    int end=-1;
    int row=0;
    int col=m-1;

    while(row<n){
        int i=row;
        int j=col;
        int curlen=0;
        while(i<n && j<m){
            if(str1[i]==str2[j]){
                curlen++;
            }else{
                curlen=0;
            }
            if(curlen>len){
                len=curlen;
                end=i;
            }
            i++;j++;
        }

        if(col>0){
            col--;
        }else{
            row++;
        }
    }

    if(end==-1){
        cout<<"-1"<<endl;
        return 0;
    }else{
        cout<<str1.substr(end-len+1,len);
    }

    return 0;
}
