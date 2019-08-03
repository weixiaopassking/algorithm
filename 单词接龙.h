#include <bits/stdc++.h>
using namespace std;
/*
leetcode 127.单词接龙 medium
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度
。转换需遵循如下规则：
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。

说明:
如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
输出: 5
解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。

思路：BFS
bfs的队列中保存的元素为 pair<string,int>, int对应找到string走了多少步
用 unordered_set 来标记是否已经访问过当前字符串
当广度优先搜索发现目标字符串时，直接返回以前搜索的步数，就是答案
如果没有访问过，将字符串和对应步数加入队列
 */

class Change {
public:
    bool strdiff(string &str1,string &str2){
        if(str1.size()!=str2.size())
            return false;
        int diff=0;
        for(int i=0;i<str1.size();++i){
            if(diff>1) return false;
            if(str1[i]!=str2[i]) diff++;
        }
        return diff==1;
    }

    int countChanges(vector<string> dic, int n, string s, string t) {
        queue<pair<string,int> > q;
        q.push(make_pair(s,0));
        unordered_set<string> st;
        int cnt=INT_MAX;

        while(!q.empty()){
            pair<string,int> cur=q.front();q.pop();
            if(cur.first==t)  return cur.second;

            if(st.find(cur.first)==st.end()){
                st.insert(cur.first);
                for(int i=0;i<n;++i){
                    if(st.find(dic[i])==st.end() && strdiff(dic[i],cur.first)){
                        q.push(make_pair(dic[i],cur.second+1));
                    }
                }
            }
        }
        return cnt==INT_MAX? -1:cnt;
    }
};
