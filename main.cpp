#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> resmp;
unordered_map<int,int> cnt;

int c(int down,int up){
    int res=1;
    for(int i=0;i<up;++i){
        res=res*down;
        down--;
    }

    while (up>0) {
        res=res/up;
        up--;
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
        cnt[num[i]]++;
    }

    int val=0;
    for(int i=mymax;i>=1;--i){
        val=+cnt[i];
        int curres=0;
        for(int j=1;j<=val;++j){
            curres+=c(val,j);
        }
        resmp[i]=curres*(total-val);
    }
    resmp[1]=1;

    double res=0.0;
    for(int i=1;i<=mymax;++i){
        res=res+i*resmp[i];
    }
    res=res/total;

    printf("%.2f\n",res);

    return 0;

}


