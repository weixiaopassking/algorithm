#include <bits/stdc++.h>

using namespace std;


int main ()
{
    clock_t start,finish;
    double totaltime;
    start=clock();

    /********************/
    // 计算程序运行时间
    // 程序主体
    std::map<char,int> first;

    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['d']=70;

    std::map<char,int,greater<int>> second (first.begin(),first.end());

    cout<<"first:"<<endl;
    for(auto i=first.begin();i!=first.end();++i){
        cout<<i->first<<", "<<i->second<<endl;
    }

    cout<<endl<<"second:"<<endl;
    for(auto i=second.begin();i!=second.end();++i){
        cout<<i->first<<", "<<i->second<<endl;
    }
    /********************/

    finish=clock();
    totaltime=(double)(finish-start);
    cout<<totaltime<<"ms"<<endl;

    return 0;
}
