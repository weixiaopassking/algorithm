#include <bits/stdc++.h>
using namespace std;

/*
leetcode 126. 单词接龙 II hard
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。
转换需遵循如下规则：
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。

说明:
如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

示例
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]


思路：

*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(int i=0;i<wordList.size();++i){
            dict.insert(wordList[i]);
        }
        dict.erase(beginWord);

        vector<vector<string>> ret;
        if(dict.find(endWord)==dict.end()) return ret;

        queue<vector<string>> paths;
        paths.push({beginWord});

        int len=INT_MAX;

        unordered_set<string> visit;
        int level=1;

        while(!paths.empty()){
            vector<string> cur(paths.front());
            paths.pop();
            if(cur.size()>=len) return ret;

            if(cur.size()>level){
                level++;
                for(string s:visit){
                    dict.erase(s);
                }
                visit.clear();
            }

            string last=cur.back();
            for(int i=0;i<last.size();++i){
                string newstr(last);
                for(int ch='a';ch<='z';++ch){
                    newstr[i]=ch;
                    if(dict.find(newstr)!=dict.end()){
                        if(newstr==endWord){
                            vector<string> ans(cur);
                            ans.push_back(endWord);
                            ret.push_back(ans);
                            len=ans.size();
                        }else{
                            vector<string> pstr(cur);
                            pstr.push_back(newstr);
                            paths.push(pstr);
                        }
                    }
                }
            }
        }
        return ret;
    }
};



/* 回溯法：以下方法超出了时间复杂度 */
// 很容易出现的一个问题是：把len以值传递传进去，
// 结果就会造成在递归程序内部len已经减小了，但在外部没有减小
// 下一次符合条件的结果就会判断比len小，把ret清空，以前的结果就不在了
// 就出现了漏掉原来的部分答案
class Solution {
public:
    string end;
    vector<string> list;
    int len;

    bool is1diff(string& str1,string& str2){
        int cnt=0;
        for(int i=0;i<str1.size();++i){
            if(str1[i]!=str2[i]) cnt++;
        }
        return cnt==1;
    }

    void helper(string& cur,vector<string>& path,vector<vector<string>>& ret,vector<int>& flag){
        if(cur==end){
            if(path.size()>len) return;
            else if(path.size()==len)
                ret.push_back(path);
            else{
                ret.clear();
                ret.push_back(path);
                len=path.size();
            }
            return;
        }

        if(path.size()>=len) return;

        for(int i=0;i<list.size();++i){
            if(flag[i]==0 && is1diff(cur,list[i])){
                cur=list[i];
                flag[i]=1;
                path.push_back(cur);
                helper(cur,path,ret,flag);
                flag[i]=0;
                path.pop_back();
                cur=path.back();
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int i=0;
        vector<vector<string>> ret;
        for(;i<wordList.size();++i){
            if(wordList[i]==endWord) break;
        }
        if(i==wordList.size())  return ret;
        end=endWord;
        list=wordList;
        string cur=beginWord;
        vector<int> flag(wordList.size(),0);
        vector<string> path;
        path.push_back(cur);
        len=INT_MAX;
        helper(cur,path,ret,flag);
        return ret;
    }
};

