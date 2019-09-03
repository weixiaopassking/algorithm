
#include<bits/stdc++.h>
using namespace std;
/*
Manacher算法求解最大回文串的长度
 */

string getstr(string& str){
    int index=0;
    string ret(str.size()*2+1,'0');
    for(int i=0;i!=ret.size();++i){
        ret[i]=(i&1)==0? '#': str[index++];
    }
    return ret;
}


int process(string& str){
    if(str.empty()){
        return 0;
    }
    string mana=getstr(str);
    vector<int> arr(mana.size());
    int index=-1;
    int r=-1;
    int max=INT_MIN;
    for(int i=0;i!=mana.size();++i){
        arr[i]=r>i? min(arr[2*index-i],r-i):1;
        while(i+arr[i]<mana.size() && i-arr[i]>-1){
            if(mana[i+arr[i]]==mana[i-arr[i]])
                arr[i]++;
            else{
                break;
            }
        }

        if(i+arr[i]>r){
            r=i+arr[i];
            index=i;
        }
        max=::max(max,arr[i]);
    }
    return max-1;
}


int main(){
    string str;
    getline(cin,str);

    cout<<process(str)<<endl;

    return 0;

}

