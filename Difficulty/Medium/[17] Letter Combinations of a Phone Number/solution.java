class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) return new ArrayList<>();
        List<String> res = new ArrayList<>();
        HashMap<Character, String> map = new HashMap<>() {
            {
                put('2', "abc");
                put('3', "def");
                put('4', "ghi");
                put('5', "jkl");
                put('6', "mno");
                put('7', "pqrs");
                put('8', "tuv");
                put('9', "wxyz");
            }
        };
        StringBuilder sBuf = new StringBuilder(digits.length());
        dfs(map, digits, res, sBuf, 0);
        return res;
    }

    public void dfs(HashMap<Character, String> map, String digits, List<String> res, StringBuilder sBuf, int i) {
        if (i == digits.length()) {
            res.add(sBuf.toString());
            return;
        }
        char c = digits.charAt(i);
        int len = map.get(c).length();
        for (int j = 0; j < len; j++) {
            sBuf.append(map.get(c).charAt(j));
            dfs(map, digits, res, sBuf, i+1);
            sBuf.deleteCharAt(sBuf.length() - 1);
        }
    }
}