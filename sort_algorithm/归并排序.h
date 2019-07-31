#include <bits/stdc++.h>
using namespace std;

/*
冒泡排序：
时间复杂度：平均nlgn，最慢nlgn,
空间O(n),稳定
*/

void merge(vector<int>& array,vector<int>& copy,int start,int rightstart,int end){
    int i=start;
    int j=rightstart;
    int idx=start;
    while(i<rightstart && j<=end){
        if(array[i]<array[j]){
            copy[idx++]=array[i++];
        }else copy[idx++]=array[j++];
    }
    while(i<rightstart) copy[idx++]=array[i++];
    while(j<=start) copy[idx++]=array[j++];

    for(int i=start;i<=end;++i){
        array[i]=copy[i];
    }
}


void mergeSort(vector<int>& array,vector<int>& copy,int start,int end){
    if(start>=end) return;
    int mid=start+(end-start)/2;
    mergeSort(array,,copy,start,mid);
    mergeSort(array,copy,mid+1,end);
    merge(array,copy,start,mid+1,end);
}
