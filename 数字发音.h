
#include <bits/stdc++.h>

using namespace std;

class ToString {
public:
    string tendigistr(int x){
        switch (x){
        case 10: return "Ten";
        case 11: return "Eleven";
        case 12: return "Twelve";
        case 13: return "Thirteen";
        case 14: return "Fourteen";
        case 15: return "Fifteen";
        case 16: return "Sixteen";
        case 17: return "Seventeen";
        case 18: return "Eighteen";
        case 19: return "Nineteen";
        }
        return "";

    }

    string tenstrfun(int x){
        switch(x){
        case 0: return "";
        //case 1: return "Ten";
        case 2: return "Twenty";
        case 3: return "Thirty";
        case 4: return "Forty";
        case 5: return "Fifty";
        case 6: return "Sixty";
        case 7: return "Seventy";
        case 8: return "Eighty";
        case 9: return "Ninety";
        }
        return "";
    }

    string digitstr(int x){
        switch (x){
        case 0: return "";
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
        }
        return "";
    }

    string numtostr(int x){
        int hund=x/100;
        int ten=(x-hund*100)/10;
        int dig=x-hund*100-ten*10;
        if(ten==1){
            string s=tendigistr(x-hund*100);
            string ret;
            if(digitstr(hund)!="") ret=digitstr(hund)+" Hundred ";
            return ret+s;
        }
        string ret;

        if(digitstr(hund)!="") ret=digitstr(hund)+" Hundred";

        if(tenstrfun(ten)!="") {
            if(ret!="")
                ret=ret+" "+tenstrfun(ten);
            else
                ret=tenstrfun(ten);
        }

        if(digitstr(dig)!="") {
            if(ret!="")
                ret=ret+" "+digitstr(dig);
            else
                ret=digitstr(dig);
        }

        return ret;
    }

    string toString(int x) {
        // write code here
        if(x==0) return "Zero";
        if(x<1000){
            return numtostr(x);
        }else if(x<1000000){
            int small=x%1000;
            string smallstr=toString(small);
            string bigstr=toString(x/1000);
            if(smallstr!="" && smallstr!="Zero") return bigstr+" Thousand,"+smallstr;
            return bigstr+" Thousand";
        }else if(x<1000000000){
            int small=x%1000000;
            string smallstr=toString(small);
            string bigstr=toString(x/1000000);
            if(smallstr!="" &&  smallstr!="Zero") return bigstr+" Million,"+smallstr;
            return bigstr+" Million";
        }else return "";
    }
};



int main ()
{

    ToString s;
    cout<<s.toString(1234);

    return 0;
}


