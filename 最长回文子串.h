#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
 leetcode 5 最长回文子串 medium
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
*/

// DP算法
string longestPalindrome(string s)
{
    if (s.empty()) return "";
    int len = s.size();
    if (len == 1)return s;
    int longest = 1;
    int start=0;
    vector<vector<int> > dp(len,vector<int>(len));
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if(i<len-1)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                start=i;
                longest=2;
            }
        }
    }
    for (int l = 3; l <= len; l++)//子串长度
    {
        for (int i = 0; i+l-1 < len; i++)//枚举子串的起始点
        {
            int j=l+i-1;//终点
            if (s[i] == s[j] && dp[i+1][j-1]==1)
            {
                dp[i][j] = 1;
                start=i;
                longest = l;
            }
        }
    }
    return s.substr(start,longest);
}


// 马拉车算法
// https://www.cnblogs.com/grandyang/p/4475985.html
string Manacher(string s) {
    // Insert '#'
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    // Process t
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter - resLen) / 2, resLen - 1);
}

int main() {
    string s1 = "12212";
    cout << Manacher(s1) << endl;
    string s2 = "122122";
    cout << Manacher(s2) << endl;
    string s = "waabwswfd";
    cout << Manacher(s) << endl;
}
