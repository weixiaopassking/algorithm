#include <bits/stdc++.h>
using namespace std;

/*
 * Leetcode 91 medium
一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

例子：
输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。

思路：用回溯方法来做
1)如果遇到单个'0'，它必须要和前面的1或2在一起，结束递归
2)遇到其他单个数的情况，继续递归
3)当前char与后面一个能构成新单词，递归去解码后面的单词

 */

void helper(string& str,vector<string>& arr,string res,int pos){
    if(pos>=str.size()){
        arr.push_back(res);
        return;
    }

    if(str[pos]=='0'){
        return;
    }else{
        char cur=(str[pos]-'0')-1+'A';
        string tmp(1,cur);
        helper(str,arr,res+tmp,pos+1);
    }

    if(pos<str.size()-1 && (str[pos]=='1' || (str[pos]=='2' && str[pos+1]<='6'))){
        char cur=(str[pos]-'0')*10+(str[pos+1]-'0')-1+'A';
        string tmp(1,cur);
        helper(str,arr,res+tmp,pos+2);
    }
}

int main(){
    string str;
    cin>>str;
    vector<string> arr;
    string res;
    helper(str,arr,res,0);

    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<endl;
    }

    return 0;
}
