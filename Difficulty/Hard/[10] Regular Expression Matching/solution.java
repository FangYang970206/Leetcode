class Solution1 {
    public static boolean isMatch(String s, String p) {
        if (s.isEmpty() && p.isEmpty()) return true;
        return isMatchHelper(s, p, 0, 0);
    }

    public static boolean isMatchHelper(String s, String p, int i, int j) {
        int slen = s.length(), plen = p.length();
        if (i == slen && j == plen) return true;
        if (i != slen && j == plen) return false;
        if (j+1 < plen && p.charAt(j+1) == '*') {
            if (i < slen && (p.charAt(j) == '.' || p.charAt(j) == s.charAt(i))) {
                return isMatchHelper(s, p, i, j+2)
                        || isMatchHelper(s, p, i+1, j)
                        || isMatchHelper(s, p, i+1, j+2);
            } else {
                return isMatchHelper(s, p, i, j+2);
            }
        }
        if (i < slen && (p.charAt(j) == '.' || p.charAt(j) == s.charAt(i))) {
            return isMatchHelper(s, p, i+1, j+1);
        }
        return false;
    }
}

class Solution2 {
    public static boolean isMatch(String s, String p) {
        int m = s.length(), n = p.length();
        boolean[][] dp = new boolean[m+1][n+1];
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p.charAt(j-1) == '*') {
                    dp[i][j] = dp[i][j-2];
                    if (matchChar(s, p, i, j-1)) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                } else if (matchChar(s, p, i, j)) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }

    public static boolean matchChar(String s, String p, int i, int j) {
        if (i == 0) return false;
        if (p.charAt(j-1) == '.') return true;
        if (s.charAt(i-1) == p.charAt(j-1)) return true;
        return false;
    }
}