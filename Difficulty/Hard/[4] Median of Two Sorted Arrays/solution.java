class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        int k = (n + m + 1) / 2;
        if ((n + m) % 2 == 0) {
            return (getKth(nums1, 0, nums2, 0, k) + getKth(nums1, 0, nums2, 0, k+1)) * 0.5;
        } else {
            return getKth(nums1, 0, nums2, 0, k);
        }
    }

    public int getKth(int[] nums1, int start1, int[] nums2, int start2, int k) {
        int len1 = nums1.length - start1;
        int len2 = nums2.length - start2;
        if (len1 > len2) return getKth(nums2, start2, nums1, start1, k);
        if (len1 == 0) return nums2[start2 + k - 1];
        if (k == 1) return Math.min(nums1[start1], nums2[start2]);
        int i = start1 + Math.min(k / 2, len1) - 1;
        int j = start2 + Math.min(k / 2, len2) - 1;
        if (nums1[i] > nums2[j]) {
            return getKth(nums1, start1, nums2, j + 1, k - (j - start2 + 1));
        } else {
            return getKth(nums1, i + 1, nums2, start2, k - (i - start1 + 1));
        }
    }
}