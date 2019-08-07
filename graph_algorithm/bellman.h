# include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<int>>& graph,vector<int>& dist,vector<int>& path,int vernum )
{
    bool flag = true;
    for( int i = 1; i <= vernum; ++i ){
        for( int j = 1; j <= vernum; ++j ){
            if( graph[i][j] != INT_MAX && dist[i] != INT_MAX &&
                    dist[j] >= dist[i] + graph[i][j] ){
                if( dist[j] > dist[i] + graph[i][j] ){
                    flag = false;
                    dist[j] = dist[i] + graph[i][j];
                    path[j] = i;
                }
            }
        }
    }
    // 最后一次如果返回flag=false，还能继续优化，说明存在负权环
    return flag;
}

bool bellman( vector<vector<int>>& graph,vector<int>& dist,vector<int>& path,int vernum ){
    // 在函数体内最多调用V-1次操作
    for( int i = 0; i < vernum - 1; ++i ){
        // 不能继续优化，提早结束，返回true
        if( check(graph,dist,path,vernum)==true )
            return true;
    }
    bool flag=check(graph,dist,path,vernum);
    return flag;
}

// 测试用例，一共有4个点，6条边，所有的边为
// 1->2,1
// 1->3,3
// 1->4,21
// 2->3,1
// 2->4,3
// 3->4,1
int main(){
    // 注意邻接矩阵没有用到graph[0]这一行
    // graph只用到了4x4的矩阵
    vector<vector<int>> graph={ {},
                                {0,0,1,3,21},
                                {0,INT_MAX,0,1,3},
                                {0,INT_MAX,INT_MAX,0,1},
                                {0,INT_MAX,INT_MAX,INT_MAX,INT_MAX}};

    vector<int> path(5,-1);

    vector<int> dist(5,INT_MAX);
    dist[1]=0;
    int vernum=4;
    if( bellman(graph,dist,path,vernum)==true){
        for( int i = 1; i <= vernum; ++i )
            printf("%d%s", dist[i], i == vernum ? "\n":" ");
        for( int i = 4; i != -1; i = path[i] )
            printf("%d ", i);
    }
    else
        printf("FALSE");
    return 0;
}

