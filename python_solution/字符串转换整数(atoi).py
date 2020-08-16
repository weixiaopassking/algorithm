# -*- coding: utf-8 -*-

'''
leetcode 8. 字符串转换整数 (atoi)

简单的分类讨论
'''


class Solution(object):
    def myAtoi(self, st):
        """
        :type str: str
        :rtype: int
        """
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        st = st.strip()
        if(len(st) == 0):
            return 0
        if st[0] == '-' or st[0] == '+':
            i = 1
            while i < len(st) and ord('0') <= ord(st[i]) and ord(st[i]) <= ord('9'):
                i += 1
            value_str = st[0:i]
            if len(value_str) == 1:
                return 0
            value = int(value_str)
            if st[0] == '-' and value < INT_MIN:
                return INT_MIN
            elif st[0] == '+' and value > INT_MAX:
                return INT_MAX
            else:
                return int(st[0:i])
        elif '0' <= st[0] <= '9':
            i = 1
            while i < len(st) and '0' <= st[i] <= '9':
                i += 1
            value = int(st[0:i])
            if value > INT_MAX:
                return INT_MAX
            elif value < INT_MIN:
                return INT_MIN
            else:
                return value
        else:
            return 0


if __name__ == "__main__":
    st = 'abc'
    print Solution().myAtoi(st)
