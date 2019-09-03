#include <bits/stdc++.h>
using namespace std;

/*
KMP算法，用来寻找str字符串中match字符串所有的位置
给定两个字符串str和match，长度分别为N和M。
实现一个算法，如果字符串str中含有子串match，则返回match在str中的开始位置，不含有则返回-1
若出现了多次，则按照升序输出所有出现位置
*/

void getnext(vector<int>& next, string& match){
    if(match.empty()) return;
    if(match.size()==1){
        next=vector<int>(1,-1);
        return ;
    }

    next=vector<int>(match.size(),0);
    next[0]=-1;
    next[1]=0;
    int cn=0;
    int i=2;
    while(i<match.size()){
        if(match[i-1]==match[cn]){
            next[i++]=++cn;
        // ！！！下面这几个语句很容易写错
        }else if(cn>0){
            cn=next[cn];
        }else{
            next[i++]=0;
        }
    }
}

vector<int> kmp(string& str,string& match){
    vector<int> ret;
    if(match.empty() || str.empty() || match.size()>str.size()){
        ret.push_back(-1);
        return ret;
    }

    int i=0;
    int j=0;
    vector<int> next;

    getnext(next,match);

    while(i<str.size()){
        if(j==match.size()){
           ret.push_back(i-match.size());
            j=0;
            i=i-match.size()+1;
        }
        if(str[i]==match[j]){
            i++;
            j++;
        // ！！！下面这几个语句很容易写错
        }else if(next[j]==-1){
            i++;
        }else{
            j=next[j];
        }
    }
    if(j==match.size()){
        ret.push_back(i-match.size());
        return ret;
    }

    if(ret.empty()) ret.push_back(-1);

    return ret;
}

int main(){
    string str;
    string match;
    cin>>str>>match;

    vector<int> ret=kmp(str,match);

    int i;

    for(i=0;i<ret.size()-1;++i) cout<<ret[i]<<" ";

    cout<<ret[i];

    return 0;
}
