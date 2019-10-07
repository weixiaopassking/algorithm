#include <bits/stdc++.h>
using namespace std;

/*
给定一个有序数组arr，调整arr使得这个数组的左半部分[1, (n+1)/2]没有重复元素且升序，
不用保证右部分是否有序.

例如，arr = [1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7, 8, 8, 8, 9]，
调整之后arr=[1, 2, 3, 4, 5, 6, 7, 8, 9, .....]。
[要求]
时间复杂度为O(n)，空间复杂度为O(1)

思路：
1.两个指针u和i，u指向左半部分的最后一个，i指向下一个要判断的数
2.i指向的数和u指向的数不同，u+1位置换成i指向的数
3.         ... 如果相同，i++

 */
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    if(n>=2){
        int i=1;
        int u=0;
        while(i<arr.size()){
            if(arr[i++]!=arr[u]){
                swap(arr[i-1],arr[++u]);
            }
        }
    }

    for(int i=0;i<n-1;++i){
        cout<<arr[i]<<" ";
    }

    cout<<arr[n-1]<<endl;

    return 0;
}
