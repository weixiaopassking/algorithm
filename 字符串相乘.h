

/*
leetcode 43. 字符串相乘 medium
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
*/

class Solution {
public:

    void stringadd(string& s1,string& s2){

        if(s1.size()<s2.size()) swap(s1,s2);
        int carry=0;
        int sum=0;
        for(int i=s1.size()-1,j=s2.size()-1;
            i>=0;--i,--j){
            if(j>=0) {
                sum=s1[i]-'0'+s2[j]-'0'+carry;
                carry=sum/10;
                s1[i]=(sum%10)+'0';
            }else{
                sum=s1[i]-'0'+carry;
                carry=sum/10;
                s1[i]=(sum%10)+'0';
            }
        }
        if(carry!=0)
            s1='1'+s1;
    }

    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        string res="0";
        for(int i=num2.size()-1;i>=0;--i){
            string str;
            int carry=0;
            for(int j=num1.size()-1;j>=0;--j){
                int mul=(num2[i]-'0')*(num1[j]-'0')+carry;
                char c=mul%10+'0';
                carry=mul/10;
                str=c+str;
            }
            if(carry!=0) str=to_string(carry)+str;
            for(int k=0;k<num2.size()-1-i;++k) str+='0';
            stringadd(res,str);

        }
        return res;
    }
};
