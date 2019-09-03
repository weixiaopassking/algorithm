#include <bits/stdc++.h>
using namespace std;

/*
有一组数，对于其中任意两个数组，若前面一个大于后面一个数字，则这两个数字组成一个逆序对。
请设计一个高效的算法，计算给定数组中的逆序对个数。
给定一个int数组A和它的大小n，请返回A中的逆序对个数。保证n小于等于5000。

测试样例：
[1,2,3,4,5,6,7,0],8
返回：7

思路：
1.归并排序的思想，将一个大数组分成两个小数组(两个小的数组已经有序，都是从小到大排列)
2.第一个数组中前面有数比第二个数组中的数大，则第一个数组中的后续数也肯定比它大
例如  [4，8，9]  [1,2,6]  4的逆序有2个，那么8也至少有两个(8有3个，前两个不用比较)，然后9不用比较，有3个。
3.归并排序放到copy的对应地方，然后需要从copy上再拷贝回来。

算法复杂度：nlgn
 */

class AntiOrder {
public:
    int ret;

    void merge(vector<int>& num,vector<int>& copy,int start,int rstart,int end){
        int i=start;
        int j=rstart;
        int k=start;
        int cnt=0;
        while(i<rstart && j<end+1){
            if(num[i]>num[j]){
                copy[k++]=num[j++];
                cnt++;
            }else{
                copy[k++]=num[i++];
                ret=cnt+ret;
            }
        }
        while(i<rstart) {
            copy[k++]=num[i++];
            ret+=cnt;
        }
        while(j<end+1) copy[k++]=num[j++];

        for(int l=start;l<=end;++l) num[l]=copy[l];
    }

    void mergesort(vector<int>& num,vector<int>& copy,int start,int end){
        if(start>=end) return;
        int mid=start+(end-start)/2;
        mergesort(num,copy,start,mid);
        mergesort(num,copy,mid+1,end);
        merge(num,copy,start,mid+1,end);
    }

    int count(vector<int> A, int n) {
        // write code here
        ret=0;
        vector<int> copy(A);
        mergesort(A,copy,0,n-1);
        return ret;
    }
};
