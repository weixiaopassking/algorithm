#include <bits/stdc++.h>
using namespace std;

/*
插入排序：
时间复杂度：平均n^2，最慢n^2,
空间O(1),稳定
*/

void insertionSort( vector<int>& array, int len ){
    for ( int p=1; p<len; p++ ) {
        int tmp = array[p]; /* 摸下一张牌 */
        int i;
        for ( i=p; i>0 && array[i-1]>tmp; i-- )
            array[i] = array[i-1]; /* 移出空位 */
        array[i] = tmp; /* 新牌落位 */
    }
}

