

/*
 *
输入 ：
3
99 51 77
91 92 49

输出：
1

输入：
3
51 77 99
51 72 92

输出：
2


输入：
3
51 77 99
51 90 92

输出：
1

输入：
2
69 91
70 91

*/

int main(){
    int n;
    cin>>n;
    vector<int> num1;
    vector<int> num2;
    for(int i=0;i<n;++i){
        int tmp;
        cin>>tmp;
        num1.push_back(tmp);
    }

    for(int i=0;i<n;++i){
        int tmp;
        cin>>tmp;
        num2.push_back(tmp);
    }

    sort(num1.begin(),num1.end(),[](int l,int r){return l>r;});
    sort(num2.begin(),num2.end(),[](int l,int r){return l>r;});

    int wincnt=0;
    for(int i=0;i<n;i++){//田忌拿出来一匹马和齐王比  赢/平/输
        int j;
        for(j=0;j<n;j++){
            if(num1[i]>num2[j]){//田忌赢
                num2[j]=INT_MAX;//标记比过赛
                wincnt++;
                break;
            }
        }
        if(j>=n)//没赢,此后永远不能赢
            break;
    }
    int tiecnt=0;// 平局计数
    for(int i=wincnt-1;i<n;i++){
        for(int j=0;j<n;j++){
            if(num1[i]==num2[j]){
                num2[j]=INT_MAX;
                tiecnt++;
                break;
            }
        }
    }
    int ret=wincnt-(n-wincnt-tiecnt);
    cout<<ret<<endl;
    return 0;
}
