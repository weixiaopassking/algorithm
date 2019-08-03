#include "solution.h"
#include <bits/stdc++.h>
using namespace std;

/*
冒泡排序：
时间复杂度：平均n^2，最慢n^2,
空间O(1),稳定
*/

void BubbleSort( vector<int>& array, int len ){
    for ( int idx=len-1; idx>=0; idx-- ){
        int flag = 0;
        for( int i=0; i<idx; i++ ) { /* 一趟冒泡 */
            if ( array[i] > array[i+1] ) {
                swap(array[i], array[i+1]);
                flag = 1; /* 标识发生了交换 */
            }
        }
        if ( flag==0 ) break; /* 全程无交换 */
    }
}

