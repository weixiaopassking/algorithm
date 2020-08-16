# -*- coding: utf-8 -*-
'''
leetcode 4 寻找两个正序数组的中位数 hard
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

思路：将nums1都和nums2分为2组
nums1[0], nums1[1], ..., nums1[i-1] | nums1[i], ..., nums1[m-1]
nums2[0], nums2[1], ..., nums2[j-1] | nums2[j], ..., nums2[m-1]
依据题意有，左边的长度=右边的长度（或右边的长度+1），转化为数学公式就是
j=(m+n+1)/2 - i
然后对i进行二分搜索并判断是否满足条件 max(nums1[i-1],nums2[j-1]) <= min(nums1[i],nums2[j])
并且需要考虑一些边界条件

示例 1:
nums1 = [1, 3], nums2 = [2], 则中位数是 2.0

示例 2:
nums1 = [1, 2], nums2 = [3, 4], 则中位数是 (2 + 3)/2 = 2.5
'''
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m, n = len(nums1), len(nums2)
        if(m > n):
            nums1, nums2, m, n = nums2, nums1, n, m

        iMin, iMax, i, half_len = 0, m, m / 2, (m + n + 1) / 2
        if n == 0:
            raise RuntimeError

        while iMin <= iMax:
            i = (iMin + iMax) / 2
            j = half_len - i

            if i > 0 and j < n and nums1[i-1] > nums2[j]:
                iMax = i - 1
            elif j > 0 and i < m and nums1[i] < nums2[j-1]:
                iMin = i + 1
            else:
                if i == 0:
                    max_of_left = nums2[j-1]
                elif j == 0:
                    max_of_left = nums1[i-1]
                else:
                    max_of_left = max(nums1[i-1], nums2[j-1])

                if (m+n) % 2 == 1:
                    return max_of_left

                if i == m:
                    min_of_right = nums2[j]
                elif j == n:
                    min_of_right = nums1[i]
                else:
                    min_of_right = min(nums1[i], nums2[j])

                return (max_of_left + min_of_right) / 2.0