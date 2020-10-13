class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        String res = new String();
        int minlen = Integer.MAX_VALUE;
        for (String s : strs) {
            if (s.isEmpty()) {
                return "";
            } else {
                if (s.length() < minlen) {
                    res = s;
                    minlen = s.length();
                }
            }
        }
        for (int i = 0; i < strs.length; i++) {
            int j = 0;
            while (j < res.length()) {
                if (res.charAt(j) != strs[i].charAt(j)) {
                    break;
                }
                j++;
            }
            res = res.substring(0, j);
        }
        return res;
    }
}