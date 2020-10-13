class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.isEmpty()) return 0;
        int[] m = new int[256];
        for (int i = 0; i < 256; i++) m[i] = -1;
        int l = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (m[s.charAt(i)] != -1) {
                int prev = m[s.charAt(i)];
                res = Math.max(res, i - l);
                while (l <= prev) {
                    m[s.charAt(l++)] = -1;
                }
            }
            m[s.charAt(i)] = i;
        }
        return Math.max(res, s.length() - l);
    }
}