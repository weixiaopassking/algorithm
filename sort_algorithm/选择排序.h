#include <bits/stdc++.h>
using namespace std;

/*
选择排序：
时间复杂度：平均n^2，最慢n^2,
空间O(1),不稳定
*/

int ScanForMin(vector<int>& array,int start,int end){
    int val=INT_MAX;
    int idx=-1;
    for(int i=start;i<=end;++i){
        if(val>array[i]){
            val=array[i];
            idx=i;
        }
    }
    return idx;
}

void selectionSort ( vector<int>& array, int len ){
    for ( int i = 0; i < len; i ++ ) {
        int MinPosition=ScanForMin(array,i,len-1);
        /* 从A[i]到A[N–1]中找最小元，并将其位置赋给MinPosition */
        swap( array[i], array[MinPosition] );
        /* 将未排序部分的最小元换到有序部分的最后位置 */
    }
}

