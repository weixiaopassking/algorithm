/*
在数组中找出由数组中字符串组成的最长的串A，即A是由其它单词组成的(可重复)最长的单词。
给定一个string数组str，同时给定数组的大小n。请返回最长单词的长度，保证题意所述的最长单词存在。
测试样例：
["a","b","c","ab","bc","abc"],6
返回：3

思路：
1.set存储数组中有的string
2.将vector<string>中的string按从大到小排列
3.递归调用判断某个字符串是否可以由其他字符串构成
 */

# include <unordered_set>

class LongestString {
public:
    unordered_set<string> st;
    bool ishave(string& str){
        if(st.find(str)!=st.end()) return true;
        for(int len=1;len<str.size();++len){
            string str1=str.substr(0,len);
            string str2=str.substr(len);
            if(ishave(str1) && ishave(str2)){
                return true;
            }
        }
        return false;

    }

    int getLongest(vector<string> str, int n) {
        // write code here
        sort(str.begin(),str.end(),[](string& l,string r){
            return l.size()>r.size();
        });
        for(string& s:str){
            st.insert(s);
        }
        for(int i=0;i<str.size();++i){
            st.erase(str[i]);
            if(ishave(str[i]))
                return str[i].size();
        }
        return 0;
    }
};
