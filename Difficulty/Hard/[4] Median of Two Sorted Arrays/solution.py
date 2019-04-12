#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#
# https://leetcode.com/problems/median-of-two-sorted-arrays/description/
#
# algorithms
# Hard (25.60%)
# Total Accepted:    409.9K
# Total Submissions: 1.6M
# Testcase Example:  '[1,3]\n[2]'
#
# There are two sorted arrays nums1 and nums2 of size m and n respectively.
# 
# Find the median of the two sorted arrays. The overall run time complexity
# should be O(log (m+n)).
# 
# You may assume nums1 and nums2Â cannot be both empty.
# 
# Example 1:
# 
# 
# nums1 = [1, 3]
# nums2 = [2]
# 
# The median is 2.0
# 
# 
# Example 2:
# 
# 
# nums1 = [1, 2]
# nums2 = [3, 4]
# 
# The median is (2 + 3)/2 = 2.5
# 
# 
#
class Solution1:
    def getMiddleValue(self, nums, nums_len):
        if nums_len % 2 == 0:
            mid_idx = nums_len // 2
            return (nums[mid_idx] + nums[mid_idx - 1])/2.0
        else:
            return nums[(nums_len - 1) // 2]/1.0
    
    def dealTheRest(self, res, nums, num1, num2, lens, lens_orig):
        while num1 > num2 and nums:
            if len(res) == 1:
                if (lens - 1) == lens_orig // 2:
                    return num1
            else:
                if (lens - 1) == lens_orig // 2:
                    res[1] = num1
                elif (lens - 1) == lens_orig // 2 - 1:
                    res[0] = num1
                    return sum(res)/2.0
            num1 = nums.pop()
            lens -= 1
        if nums:
            if (lens - 1) == lens_orig // 2:
                if len(res) == 1:
                    return num2
                else:
                    res[1] = num2
            while (lens - 1) >= (lens_orig - 1) // 2:
                if (lens - 1) == lens_orig // 2:
                    if len(res) == 1:
                        return num1
                    else:
                        res[1] = num1
                elif (lens - 1) == lens_orig // 2 - 1:
                    res[0] = num1
                    return sum(res)/2.0
                num1 = nums.pop()
                lens -= 1
        else:
            if num1 > num2:
                return num1
            else:
                return num2
        return res

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if not nums1:
            return self.getMiddleValue(nums2, len(nums2))
        if not nums2:
            return self.getMiddleValue(nums1, len(nums1))
        lens = len(nums1) + len(nums2)
        lens_orig = lens
        if lens % 2 == 0:
            res = [0] * 2
        else:
            res = [0]
        num1 = nums1.pop()
        num2 = nums2.pop()
        
        if not nums1 and not nums2:
            return (num1 + num2)/2.0
        while nums1 and nums2:
            if num1 > num2:
                if len(res) == 1:
                    if (lens - 1) == lens_orig // 2:
                        return num1
                else:
                    if (lens - 1) == lens_orig // 2:
                        res[1] = num1
                    elif (lens - 1) == lens_orig // 2 - 1:
                        res[0] = num1
                        return sum(res)/2.0
                num1 = nums1.pop()
            else:
                if len(res) == 1:
                    if (lens - 1) == lens_orig // 2:
                        return num2
                else:
                    if (lens - 1) == lens_orig // 2:
                        res[1] = num2
                    elif (lens - 1) == lens_orig // 2 - 1:
                        res[0] = num2
                        return sum(res)/2.0
                num2 = nums2.pop()
            lens -= 1
        if nums1:
            return self.dealTheRest(res, nums1, num1, num2, lens, lens_orig)
        if nums2:
            return self.dealTheRest(res, nums2, num2, num1, lens, lens_orig)

class Solution2:
    def getMiddleValue(self, nums, nums_len):
        if nums_len % 2 == 0:
            mid_idx = nums_len // 2
            return (nums[mid_idx] + nums[mid_idx - 1])/2.0
        else:
            return nums[(nums_len - 1) // 2]/1.0

    def dealTheRest(self, res, nums, num1, num2, lens, lens_orig):
        while num1 > num2 and nums:
            temp = self.judgeReturnValue(num1, lens, lens_orig, res)
            if temp != 'N':
                return temp
            num1 = nums.pop()
            lens -= 1
        if nums:
            temp = self.judgeReturnValue(num2, lens, lens_orig, res)
            if temp != 'N':
                return temp
            lens -= 1
            while (lens - 1) >= (lens_orig - 1) // 2:
                temp = self.judgeReturnValue(num1, lens, lens_orig, res)
                if temp != 'N':
                    return temp
                num1 = nums.pop()
                lens -= 1
        else:
            if num1 > num2:
                res[0] = num1
            else:
                res[0] = num2
        return sum(res)/len(res)
    
    def judgeReturnValue(self, num, lens, lens_orig, res):
        if (lens - 1) == lens_orig // 2:
            if len(res) == 1:
                return num/1.0
            else:
                res[1] = num
        elif (lens - 1) == lens_orig // 2 - 1:
            res[0] = num
            return sum(res)/2.0
        return 'N'

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if not nums1:
            return self.getMiddleValue(nums2, len(nums2))
        if not nums2:
            return self.getMiddleValue(nums1, len(nums1))
        lens = len(nums1) + len(nums2)
        lens_orig = lens
        if lens % 2 == 0:
            res = [0] * 2
        else:
            res = [0]
        num1 = nums1.pop()
        num2 = nums2.pop()
        
        if not nums1 and not nums2:
            return (num1 + num2)/2.0
        while nums1 and nums2:
            if num1 > num2:
                temp = self.judgeReturnValue(num1, lens, lens_orig, res)
                if temp != 'N':
                    return temp
                num1 = nums1.pop()
            else:
                temp = self.judgeReturnValue(num2, lens, lens_orig, res)
                if temp != 'N':
                    return temp
                num2 = nums2.pop()
            lens -= 1
        if nums1:
            return self.dealTheRest(res, nums1, num1, num2, lens, lens_orig)
        if nums2:
            return self.dealTheRest(res, nums2, num2, num1, lens, lens_orig)
