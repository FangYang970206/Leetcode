class Solution {
    public int trap(int[] height) {
        if (height.length == 0) return 0;
        int len = height.length;
        int left = 0, right = len - 1;
        int leftMax = height[0], rightMax = height[len-1];
        int res = 0;
        while (left <= right) {
            leftMax = Math.max(leftMax, height[left]);
            rightMax = Math.max(rightMax, height[right]);
            if (leftMax > rightMax) {
                res += rightMax - height[right];
                right--;
            } else {
                res += leftMax - height[left];
                left++;
            }
        }
        return res;
    }
}