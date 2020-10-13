class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        int slen = s.length(), wsLen = words.length;
        List<Integer> res = new ArrayList<>();
        if (slen == 0 || wsLen == 0) return res;
        HashMap<String, Integer> wsMap = new HashMap<>();
        for (String word : words) {
            if (wsMap.get(word) == null) wsMap.put(word, 0);
            wsMap.put(word, wsMap.get(word) + 1);
        }
        int i = 0, wlen = words[0].length();
        HashMap<String, Integer> seen = new HashMap<>();
        while (i <= slen - wlen * wsLen) {
            int j = 0;
            while (j < wsLen) {
                String tmp = s.substring(i+j*wlen, i+(j+1)*wlen);
                if (wsMap.containsKey(tmp)) {
                    if (seen.get(tmp) == null) seen.put(tmp, 0);
                    seen.put(tmp, seen.get(tmp) + 1);
                    if (seen.get(tmp) > wsMap.get(tmp)) {
                        break;
                    }
                } else {
                    break;
                }
                j++;
            }
            seen.clear();
            if (j == wsLen) res.add(i);
            i++;
        }
        return res;
    }
}