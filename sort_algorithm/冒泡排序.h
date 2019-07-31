#include "solution.h"
#include <bits/stdc++.h>
using namespace std;

/*
冒泡排序：
时间复杂度：平均n^2，最慢n^2,
空间O(1),稳定
*/

void BubbleSort( vector<int>& A, int N ){
    for ( int P=N-1; P>=0; P-- ){
        int flag = 0;
        for( int i=0; i<P; i++ ) { /* 一趟冒泡 */
            if ( A[i] > A[i+1] ) {
                swap(A[i], A[i+1]);
                flag = 1; /* 标识发生了交换 */
            }
        }
        if ( flag==0 ) break; /* 全程无交换 */
    }
}

