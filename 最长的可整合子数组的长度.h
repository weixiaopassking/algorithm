#include <bits/stdc++.h>
using namespace std;

/*
一个数组在排序之后，每相邻两个数的差的绝对值都为1，或者该数组长度为1，则该数组为可整合数组。
给定一个数组arr, 请返回其中最大可整合子数组的长度。
例如，[5, 3, 4, 6, 2]排序后为[2, 3, 4, 5, 6]，所以这个数组为可整合数组
例如，[5, 5, 3, 2, 6, 4, 3]的最大可整合子数组为[5, 3, 2, 6, 4]，所以请返回5
 */

int main(){
    int n;
    scanf("%d", &n);
    if (n <= 0){
        printf("0");
        return 0;
    }
    else if (n == 1){
        printf("1");
        return 0;
    }

    vector<int> arr(n,0);
    for(int i=0;i<n;++i){
        scanf("%d", &arr[i]);
    }

    int res=1;
    unordered_set<int> st;
    for(int i=0;i<n;++i){
        if(res>=n-i-1){
            break;
        }
        int minval=INT_MAX;
        int maxval=INT_MIN;

        for(int j=i;j<n;++j){
            if(st.find(arr[j])!=st.end()){
                break;
            }

            st.insert(arr[j]);
            minval=min(arr[j],minval);
            maxval=max(arr[j],maxval);
            if(maxval-minval==j-i){
                res=max(res,j-i+1);
            }
        }
        st.clear();
    }

    cout<<res<<endl;

    return 0;
}
