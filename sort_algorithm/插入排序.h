#include <bits/stdc++.h>
using namespace std;

/*
插入排序：
时间复杂度：平均n^2，最慢n^2,
空间O(1),稳定
*/

void insertionSort( vector<int>& A, int N ){
    for ( int p=1; p<N; p++ ) {
        int tmp = A[p]; /* 摸下一张牌 */
        int i;
        for ( i=p; i>0 && A[i-1]>tmp; i-- )
            A[i] = A[i-1]; /* 移出空位 */
        A[i] = tmp; /* 新牌落位 */
    }
}

