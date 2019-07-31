#include <bits/stdc++.h>
using namespace std;

/*
快速排序：
每次选择把最后一个数最为pivot，但也可以选择中间或者前面的数
时间复杂度：nlgn~n^2,空间复杂度 O(logN)递归调用的堆栈, 不稳定
*/

void Quicksort( vector<int>& A, int left, int right ){
    if(left>=right) return;
    // 把最后一个数作为pivot
    int pivot = A[right];
    int i = left;
    int j = right-1;
    for(;;) {
        while (i<right && A[i] < pivot ){i++;};
        while (j>i && A[j] > pivot ){j--;};
        if ( i < j ){
            swap( A[i], A[j] );
            i++;j--;
        }
        else break;
    }
    swap( A[i], A[right] );
    Quicksort( A, left, i-1 );
    Quicksort( A, i+1, right );
}


