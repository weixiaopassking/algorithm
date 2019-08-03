#include <bits/stdc++.h>
using namespace std;

/*
leetcode 3.无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

思路：

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;

        int res=0;
        unordered_map<char,int> mp;
        for(int i=0,j=0;i<s.size()&& j<s.size();){
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]=j+1;
                res=max(res,j-i+1);
                ++j;
            }else{
                i=max(mp[s[j]],i);
                res=max(res,j-i+1);
                mp[s[j]]=j+1;
                ++j;
            }
        }

        return res;
    }
};
