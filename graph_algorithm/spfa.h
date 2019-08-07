#include<bits/stdc++.h>
using namespace std;

struct graph_table{
    int vertex;
    int weight;
    graph_table(int x,int y) :
        vertex(x), weight(y) {
    }
};

/*
 * 输入gt：邻接表
 * dist ： 与源点的距离值
 * src  ： 源点
 *  n   ：一共有几个顶点
 */

int spfa(vector<vector<graph_table>>& gt,vector<int>& dist,int src,int n){
    vector<int> visited(n+1,0);

    // 初始化d数组，赋为无穷远
    for(int i=1;i<=n;++i)
        dist[i]=INT_MAX;

    queue<int> q;
    // 把源点k放入队列
    q.push(src);
    // 源点与源点的距离为0
    dist[src]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        int v;
        visited[u]=0;
        for(int i=0;i<gt[u].size();++i){
            // 枚举所有的路径
            v=gt[u][i].vertex;
            if(dist[v]>dist[u]+gt[u][i].weight){
                // src->v的距离大于 src->u->v,更新
                dist[v] = dist[u]+gt[u][i].weight;
                if(!visited[v]) {
                    q.push(v);
                    visited[v]=1;
                }
            }
        }
    }

    for(int i=1;i<=n;++i)
        cout<<dist[i]<<" ";
    return 0;
}


int main(){
    // 测试用例，一共有4个点，6条边，所有的边为
    // 1->2,1
    // 1->3,3
    // 1->4,21
    // 2->3,1
    // 2->4,3;
    // 3->4,1
    vector<vector<graph_table>> gt;
    vector<graph_table> tmp;
    gt.push_back(tmp);

    // 节点1的邻接表
    graph_table g1(2,1);
    tmp.push_back(g1);
    g1.vertex=3;g1.weight=3;
    tmp.push_back(g1);
    g1.vertex=4;g1.weight=21;
    tmp.push_back(g1);
    gt.push_back(tmp);

    // 节点2
    tmp.clear();
    g1.vertex=3;g1.weight=1;
    tmp.push_back(g1);
    g1.vertex=4;g1.weight=3;
    tmp.push_back(g1);
    gt.push_back(tmp);

    // 节点3
    tmp.clear();
    g1.vertex=4;g1.weight=1;
    tmp.push_back(g1);
    gt.push_back(tmp);

    // 节点4
    tmp.clear();
    gt.push_back(tmp);

    vector<int> dis(5,0);
    spfa(gt,dis,1,4);
    return 0;
}

