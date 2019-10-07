#include<bits/stdc++.h>
using namespace std;

/*
LeetCode 786. 第 K 个最小的素数分数  hard
一个已排序好的表 A，其包含 1 和其他一些素数.  当列表中的每一个 p<q 时，我们可以构造一个分数 p/q 。
那么第 k 个最小的分数是多少呢?
以整数数组的形式返回你的答案, 这里 answer[0] = p 且 answer[1] = q.

示例:
输入: A = [1, 2, 3, 5], K = 3
输出: [2, 5]
解释:
已构造好的分数,排序后如下所示:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
很明显第三个最小的分数是 2/5.
*/

vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    /*
     * PriorityQueue with optimization
     * 核心思想：使用最小堆，pop一次，加一个数，再pop，再加...
     * pop K-1次后得到Kth小的数
     */
    int n=A.size();
    std::priority_queue<pair<double,pair<int,int>>,
            std::vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> pq;

    for(int i=0;i<n-1;++i)
    {
        int p=A[i];
        int q=A[n-1];
        pq.push(make_pair( (double)p/(double)q, make_pair(i,n-1)));
    }

    while(--K > 0)//K-1 次
    {
        auto element=pq.top().second;
        pq.pop();
        if(element.second-element.first>1)
        {
            int p=A[element.first];
            int q=A[element.second-1];
            pq.push(make_pair( ((double)p)/(double)q,make_pair(element.first,element.second-1)));
        }
    }

    return {A[pq.top().second.first],A[pq.top().second.second]};
}


// 下面的做法会超时
vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    /*
     * PriorityQueue-based solution
     * exceeded the time limit
     */
    size_t n=A.size();
    //size_t total_num=n*(n-1)/2;
    //if(K>total_num) return res;

    sort(A.begin(),A.end());
    auto cmp = [](std::pair<int,int> left, std::pair<int,int> right)
    { return left.first*right.second < right.first*left.second;};
    std::priority_queue<pair<int,int>, std::vector<pair<int,int>>, decltype(cmp)> pq(cmp);
    for(int i=0;i<n-1;++i)//分子
    {
        for(int j=i+1;j<n;++j)//分母
        {
            pq.push(make_pair(A[i],A[j]));
            // printf("%d/%d ",pq.top().first,pq.top().second);
            if(pq.size()>K)
            {
                //printf("%d/%d ",pq.top().first,pq.top().second);
                pq.pop();
            }
        }
    }
    return {pq.top().first,pq.top().second};
}
