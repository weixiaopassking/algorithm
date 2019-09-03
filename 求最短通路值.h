
#include<bits/stdc++.h>
using namespace std;

/*
用一个整形矩阵matrix表示一个网格，1代表有路，0代表无路，
每一个位置只要不越界，都有上下左右四个方向，
求从最左上角到右下角的最短通路值
例如，matrix为：
1 0 1 1 1
1 0 1 0 1
1 1 1 0 1
0 0 0 0 1
通路只有一条，由12个1构成，所以返回12
[要求]
时间复杂度为O(nm)，空间复杂度为O(nm)

思路：典型的BFS
从[0,0]出发，把周围有效的点都放进队列中，并把这些有效点改为无效，防止下次重入
队列q中放的是cur数组，3个元素分别代表行，列，距离值。
 */


int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<string> mat(n,"");
    for(int i=0;i<n;++i){
        cin>>mat[i];
    }

    queue<vector<int>> q;
    vector<int> cur={0,0,1};
    q.push(cur);
    mat[0][0]='2';
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    while(!q.empty()){
        cur=q.front();q.pop();
        int row=cur[0];
        int col=cur[1];
        int path=cur[2];

        if(row==n-1 && col ==m-1){
            cout<<path<<endl;
            return 0;
        }

        for(int i=0;i<4;++i){
            int currow=row+dir[i][0];
            int curcol=col+dir[i][1];
            if(curcol>=0 && curcol<m && currow>=0 && currow<n && mat[currow][curcol]=='1'){
                mat[currow][curcol]='2';
                cur[0]=currow;
                cur[1]=curcol;
                cur[2]=path+1;
                q.push(cur);
            }
        }
    }

    cout<<"-1"<<endl;

    return 0;
}
