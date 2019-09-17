#include <bits/stdc++.h>
using namespace std;

/*
arr长度为1时，arr[0]是局部最小。
arr的长度为N(N>1)时:比相邻的数都要小，就叫局部最小(包括边界）。
给定无序数组arr，arr中任意两个相邻的数不相等。
写一个函数，只需返回arr中任意一个局部最小出现的【！！！位置！！！】即可

示例
输入
3
2 1 3
输出
1

思路：二分法
1）先检查左右两边是否符合条件，
2）不符合条件下用二分法查找一个arr[mid],arr[mid]<arr[mid+1]和arr[mid-1]时，
   这个mid就是要输出的，否则从肯定存在答案的地方迭代去找。

 */


#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    scanf("%d", &n);

    vector<int> arr(n,0);
    for(int i=0;i<n;++i){
        scanf("%d", &arr[i]);
    }
    if (n <= 0){
        printf("-1");
        return 0;
    }
    else if (n == 1){
        cout<<"0"<<endl;
        return 0;
    }

    if(arr[0]<arr[1]){
        cout<<"0"<<endl;
        return 0;
    }

    if(arr[n-1]<arr[n-2]){
        cout<<n-1<<endl;
        return 0;
    }

    int left=1;
    int right=n-2;
    while(left<right){
        int mid=left+(right-left)/2;
        if(arr[mid]>arr[mid+1]){
            left=mid;
        }else if(arr[mid]>arr[mid-1]){
            right=mid;
        }else{
            cout<<mid<<endl;
            return 0;
        }
    }
    cout<<left<<endl;

    return 0;
}
