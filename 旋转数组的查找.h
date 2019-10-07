#include <solution.h>
#include <bits/stdc++.h>
using namespace std;

/*
旋转数组的查找。

测试样例：
[6,1,2,3,4,5],6,6
返回：0

思想：
二分查找，主要分3中情况：
1.[1...3...5]
2.[6...3...5]
3.[6...10...5]

*/

class Finder {
public:
    int findElement(vector<int> A, int n, int x) {
        int low=0;
        int high=n-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(low==high) return low;
            if(A[mid]==x) return mid;
            if(A[low]==x) return low;
            if(A[high]==x) return high;

            if(A[low]<A[high] ){
                if(x>A[mid]) low=mid+1;
                else high=mid-1;
            }else{
                if(A[mid]<A[low]){
                    if(x<A[mid] || x>A[low]){
                        high=mid-1;
                    }else{
                        low=mid+1;
                    }
                }else{
                    if(x>A[mid] || x<A[high]){
                        low=mid+1;
                    }else{
                        high=mid-1;
                    }
                }
            }
        }
        return low;
    }
};
