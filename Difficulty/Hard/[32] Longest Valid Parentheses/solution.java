class Solution {
    public int longestValidParentheses(String s) {
        int len = s.length(), res = 0;
        int[] dp = new int[len+1];
        for (int i = 2; i <= s.length(); i++) {
            if (s.charAt(i-1) == ')') {
                if (s.charAt(i-2) == '(') {
                    dp[i] = dp[i-2] + 2;
                } else {
                    if (dp[i-1] > 0 && i-dp[i-1]-2 >= 0 && s.charAt(i-dp[i-1]-2) == '(') {
                        dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                    }
                }
            }
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}