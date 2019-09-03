/*
洪水从(0,0)的格子流到这个城市，在这个矩阵中有的格子有一些建筑，洪水只能在没有建筑的格子流动。
请返回洪水流到(n - 1,m - 1)的最早时间,
(洪水只能从一个格子流到其相邻的格子且洪水单位时间能从一个格子流到相邻格子)。
map[i][j]表示坐标为(i,j)的格子，值为1代表该格子有建筑，0代表没有建筑。
同时给定矩阵的大小n和m(n和m均小于等于100)，
请返回流到(n - 1,m - 1)的最早时间。保证洪水一定能流到终
点。

思路：
典型的BFS，
！！！注意审题，不是dp，因为洪水可能会往回流动，
而不是一直向右下方流动。
*/


#include <bits/stdc++.h>
using namespace std;

class Flood {
public:
    vector<vector<int> > dir={{0,1},{0,-1},{-1,0},{1,0}};

    int floodFill(vector<vector<int> > map, int n, int m) {
        vector<vector<int> > time(n,vector<int>(m,INT_MAX));
        vector<vector<int> > flag(n,vector<int>(m,0));
        time[0][0]=0;
        queue<vector<int>> q;
        vector<int> tmp(2,0);
        q.push(tmp);
        while(!q.empty()){
            vector<int> cur=q.front();
            q.pop();
            for(int i=0;i<dir.size();++i){
                int x=cur[0]+dir[i][0];
                int y=cur[1]+dir[i][1];
                if(x>=0 && x<n && y>=0 && y<m && map[x][y] ==0 && flag[x][y]==0){
                    time[x][y]=time[cur[0]][cur[1]]+1;
                    flag[x][y]=1;
                    tmp[0]=x;tmp[1]=y;
                    q.push(tmp);
                }
            }

        }
        return time[n-1][m-1];

    }
};

int main(){
Flood s;
    vector<vector<int>> map={{0,1},{0,1},{0,0},{0,0}};
    cout<<s.floodFill(map,4,2)<<endl;

    return 0;
}
