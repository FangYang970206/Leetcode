class Solution1 {
    public String longestPalindrome(String s) {
        String res = new String();
        for (int i = 0; i < s.length(); i++) {
            String oddStr = centerAround(s, i, i);
            String evenStr = centerAround(s, i, i+1);
            if (oddStr.length() > res.length()) res = oddStr;
            if (evenStr.length() > res.length()) res = evenStr;
        }
        return res;
    }

    public String centerAround(String s, int i, int j) {
        int len = s.length();
        while (i >= 0 && j < len) {
            if (s.charAt(i) == s.charAt(j)) {
                i--; j++;
            } else {
                break;
            }
        }
        return s.substring(i+1, j);
    } 
}

class Solution2 {
    public String longestPalindrome(String s) {
        if (s.isEmpty()) return "";
        int begin = 0, maxLen = 1;
        int len = s.length();
        boolean[][] dp = new boolean[len][len];
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }
        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = (j - i == 1) || dp[i+1][j-1];
                } else {
                    dp[i][j] = false;
                }
                if (dp[i][j] && j - i + 1 > maxLen) {
                    begin = i;
                    maxLen = j-i+1;
                }
            }
        }
        return s.substring(begin, maxLen+begin);
    }
}