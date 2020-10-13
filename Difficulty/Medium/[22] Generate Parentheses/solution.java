class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        StringBuilder sBuf = new StringBuilder(2*n);
        dfs(res, sBuf, 0, 0, n);
        return res;
    }

    void dfs(List<String> res, StringBuilder sBuf, int lnum, int rnum, int n) {
        if (lnum == n && rnum == n) {
            res.add(sBuf.toString());
            return;
        }
        if (lnum < n) {
            sBuf.append('(');
            dfs(res, sBuf, lnum+1, rnum, n);
            sBuf.deleteCharAt(sBuf.length() - 1);
        }
        if (rnum < n && rnum < lnum) {
            sBuf.append(')');
            dfs(res, sBuf, lnum, rnum+1, n);
            sBuf.deleteCharAt(sBuf.length() - 1);
        }
    }
}