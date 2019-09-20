class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if n == 0:
            return None
        if m == 0:
            for i in range(n):
                nums1[i] = nums2[i]
            return None
        if nums2[0] > nums1[m - 1]:
            for i in range(n):
                nums1[m + i] = nums2[i]
        if nums2[n - 1] < nums1[0]:
            for i in range(m - 1, -1, -1):
                nums1[n + i] = nums1[i]
            for i in range(n):
                nums1[i] = nums2[i]
            return None
        s1_i, s2_i, i = m - 1, n - 1, 1
        while s1_i >= 0 and s2_i >= 0:
            if nums1[s1_i] > nums2[s2_i]:
                nums1[m + n - i] = nums1[s1_i]
                s1_i -= 1
            else:
                nums1[m + n - i] = nums2[s2_i]
                s2_i -= 1
            i += 1
        if s1_i < 0:
            for j in range(s2_i + 1):
                nums1[j] = nums2[j]
        return None