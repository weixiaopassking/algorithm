#include<bits/stdc++.h>
using namespace std;

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        // write code here
        stack<int> st;
        ListNode* cur=pHead;
        while(!cur){
            st.push(cur->val);
            cur=cur->next;
        }
        cur=pHead;
        int sz=st.size();
        for(int i=0;i<sz;++i){
            if(st.top()!=cur->val) return false;
            st.pop();
            cur=cur->next;
        }
        return true;
    }
};
