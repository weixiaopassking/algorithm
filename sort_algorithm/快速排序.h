#include <bits/stdc++.h>
using namespace std;

/*
快速排序：
每次选择把最后一个数最为pivot，但也可以选择中间或者前面的数
时间复杂度：nlgn~n^2,空间复杂度 O(logN)递归调用的堆栈, 不稳定
*/

void Quicksort( vector<int>& array, int left, int right ){
    if(left>=right) return;
    // 把最后一个数作为pivot
    int pivot = array[right];
    int i = left;
    int j = right-1;
    for(;;) {
        while (i<right && array[i] < pivot ){i++;};
        while (j>i && array[j] > pivot ){j--;};
        if ( i < j ){
            swap( array[i], array[j] );
            i++;j--;
        }
        else break;
    }
    swap( array[i], array[right] );
    Quicksort( array, left, i-1 );
    Quicksort( array, i+1, right );
}


