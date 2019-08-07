#include <bits/stdc++.h>
using namespace std;

/*
 * vs -- 起始顶点(start vertex)
 * prev -- 前驱顶点数组。
 * dist -- 长度数组。
 * mMatrix --  图以邻接矩阵的形式进行表示
 */
void dijkstra(int vs, vector<vector<int>>& mMatrix,
              vector<int>& dist,int mVexNum){
    // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取
    // 节点号1-mVexNum
    int flag[mVexNum+1];

    // 初始化
    for (int i = 1; i <=mVexNum; i++){
        flag[i] = 0;              // flag=0，没有被选中
        dist[i] = mMatrix[vs][i]; // 顶点i的最短路径为"顶点vs"到"顶点i"的权。
    }

    // 对"顶点vs"自身进行初始化
    flag[vs] = 1;
    dist[vs] = 0;

    // 遍历mVexNum-1次；每次找出一个顶点的最短路径
    for (int i = 1; i < mVexNum; i++){
        // 寻找当前最小的路径
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)
        int min = INT_MAX;
        int k=-1;
        for (int j = 1; j <= mVexNum; j++){
            if (flag[j]==0 && dist[j]<min){
                min = dist[j];
                k = j;
            }
        }
        // 顶点k放入已经访问过的集合
        flag[k] = 1;

        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"
        for (int j = 1; j <= mVexNum; j++) {
            int tmp = (mMatrix[k][j]==INT_MAX ? INT_MAX : (min + mMatrix[k][j]));
            if (flag[j] == 0 && (tmp  < dist[j]) ){
                dist[j] = tmp;
            }
        }
    }

    // 打印dijkstra最短路径的结果
    for (int i = 1; i <= mVexNum; i++)
        cout << "shortest(" <<vs<< ", " << i << ")=" << dist[i] << endl;
}

// 测试用例，一共有4个点，6条边，所有的边为
// 1->2,1
// 1->3,3
// 1->4,21
// 2->3,1
// 2->4,3;
// 3->4,1
int main(){
    vector<vector<int>> graph={{},
                               {0,0,1,3,21},
                               {0,INT_MAX,0,1,3},
                               {0,INT_MAX,INT_MAX,0,1},
                               {0,INT_MAX,INT_MAX,INT_MAX,INT_MAX}};
    // 注意邻接矩阵没有用到graph[0]这一行
    // graph只用到了4x4的矩阵
    vector<int> dist(5,0);
    dijkstra(1,graph,dist,4);
    return 0;
}
