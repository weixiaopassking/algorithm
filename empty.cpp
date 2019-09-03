/*

int main(){
    vector<int> even;
    vector<int> odd;
    string str;
    cin>>str;

    int i=0;
    int cur=0;
    for(i=0;i<str.size();++i){
        if(str[i]==';'){
            if(cur&1){
                odd.push_back(cur);
            }else{
                even.push_back(cur);
            }
            break;
        }else if(str[i]==','){
            if(cur&1){
                odd.push_back(cur);
            }else{
                even.push_back(cur);
            }
            cur=0;
        }else{
            cur=cur*10+str[i]-'0';
        }
    }

    ++i;
    int n=0;
    for(;i<str.size();++i){
        n=10*n+str[i]-'0';
    }
    sort(odd.begin(),odd.end(),[](int& l,int &r){return l>=r;});
    sort(even.begin(),even.end(),[](int& l,int &r){return l>=r;});

    int cnt=0;

    if(n<=even.size()){
        for(;cnt<n-1;++cnt){
            cout<<even[cnt]<<",";
        }
        cout<<even[cnt]<<endl;
        return 0;
    }else{
        for(int& val:even){
            cout<<val<<",";
        }
        int rest=n-even.size();
        int ii=0;
        for(;ii<rest-1;++ii){
            cout<<odd[ii]<<',';
        }
        cout<<odd[ii]<<endl;
        return 0;
    }

    return 0;
}

 */


/*
#include<bits/stdc++.h>
using namespace std;


unordered_map<int,int> mp;

void helper(vector<int> &num, vector<int>& cur,int index,int n){
    if(index>=n){
        int mymax=INT_MIN;
        for(int i=0;i<cur.size();++i){
            mymax=max(mymax,cur[i]);
        }
        mp[mymax]++;
        return ;
    }
    for(int i=1;i<=num[index];++i){
        cur.push_back(i);
        helper(num,cur,index+1,n);
        cur.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> num(n);
    int mymax=INT_MIN;
    double total=1.0;
    for(int i=0;i<n;++i){
        cin>>num[i];
        mymax=max(mymax,num[i]);
        total=total*num[i];
    }

    vector<int> cur;
    helper(num,cur,0,n);

    double res=0;
    for(int i=1;i<=mymax;++i){
        res=res+i*mp[i];
    }
    res=res/total;

    printf("%.2f",res);

    return 0;

}



 */
