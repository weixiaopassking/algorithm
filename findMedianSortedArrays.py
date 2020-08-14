# -*- coding: utf-8 -*-

# 寻找两个正序数组的中位数
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


if __name__ == "__main__":
    nums1 = [1, 4, 7, 9, 10, 11, 40]
    nums2 = [3, 6]
    nums3 = nums1[1:3]
    print nums3
    print Solution().findMedianSortedArrays(nums1, nums2)
