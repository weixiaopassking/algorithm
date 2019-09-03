
/*
给定排序数组arr和整数k，不重复打印arr中所有相加和为k的不降序三元组
例如, arr = [-8, -4, -3, 0, 1, 2, 4, 5, 8, 9], k = 10，打印结果为：

-4 5 9
-3 4 9
-3 5 8
0 1 9
0 2 8
1 4 5

[要求]
时间复杂度为O(n^2)O(n^2)，空间复杂度为O(1)
 */

#include <bits/stdc++.h>
using namespace std;

void printnum(vector<int>& arr,int i,int low,int high,long k){
    if(low>=high) return;
    while(low<high){
        long sum=arr[low]+arr[high];
        if(sum==k-arr[i]){
            if(arr[low]!=arr[low-1])
                cout<<arr[i]<<" "<<arr[low]<<" "<<arr[high]<<endl;
            low++;
            high--;
        }else if(sum<k-arr[i]){
            low++;
        }else{
            high--;
        }
    }
}

int main(){
    int n;long k;
    cin>>n>>k;
    vector<int> arr(n,0);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    for(int i=0;i<n-2;++i){
        if(i==0 || arr[i]!=arr[i-1])
            printnum(arr,i,i+1,n-1,k);
    }

    return 0;
}

