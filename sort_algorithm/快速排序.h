#include <bits/stdc++.h>
using namespace std;

/*
快速排序：
每次选择把最后一个数最为pivot，但也可以选择中间或者前面的数
时间复杂度：nlgn~n^2,空间复杂度 O(logN)递归调用的堆栈, 不稳定
*/

// 快速排序的递归实现
void quicksort_re( vector<int>& array, int left, int right ){
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
    quicksort_re( array, left, i-1 );
    quicksort_re( array, i+1, right );
}


/*===================================================*/

// 以下是快排的非递归实现
// 主要思想就是用栈来保存每次要排序的双指针区域
int Pritation(vector<int>& a, int left, int right)
{
    if (a.empty() || left < 0 || right <= 0||left>=right)
        return -1;
    int priot = a[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && a[j] >= priot)
            j--;
        if(i<j)
            a[i]=a[j];
        while (i < j && a[i] <= priot)
            i++;
        if(i<j)
            a[j]=a[i];
    }
    a[i] = priot;
    return i;
}

void quickSort(vector<int>& a, int left,int right)
{
    if (a.empty() || left < 0 || right <= 0 || left>right)
        return;
    stack<int>temp;
    int i, j;
    //（注意保存顺序）先将初始状态的左右指针压栈
    temp.push(right);//先存右指针
    temp.push(left);//再存左指针
    while (!temp.empty())
    {
        i = temp.top();//先弹出左指针
        temp.pop();
        j = temp.top();//再弹出右指针
        temp.pop();
        if (i < j)
        {
            int k = Pritation(a, i, j);
            if (k > i)
            {
                temp.push(k - 1);//保存中间变量
                temp.push(i);  //保存中间变量
            }
            if (j > k)
            {
                temp.push(j);
                temp.push(k + 1);
            }
        }

    }
}

int main(){
    vector<int> a={1,6,3,5,2,8,9,10,34,56,4};
    quickSort(a,0,a.size()-1);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}


