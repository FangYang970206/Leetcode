class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) return s;
        int len = s.length(), loop = 2 * numRows - 2;
        StringBuilder res = new StringBuilder(len);
        for (int row = 0; row < numRows; row++) {
            int i = 0;
            if (row == 0 || row == numRows - 1) {
                while (row + i * loop < len) res.append(s.charAt(row + i++*loop));
            } else {
                while (row + i * loop < len) {
                    res.append(s.charAt(row + i * loop));
                    if (i * loop + (loop - row) < len) {
                        res.append(s.charAt(i * loop + (loop - row)));
                    }
                    i += 1;
                }
            } 
        }
        return res.toString();
    }
}