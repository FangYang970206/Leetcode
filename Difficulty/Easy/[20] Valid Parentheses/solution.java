class Solution {
    public boolean isValid(String s) {
        if (s.isEmpty()) return true;
        Stack<Character> st = new Stack<>();
        int i = 0, len = s.length();
        while (i < len) {
            if (isLeftParent(s.charAt(i))) {
                st.push(s.charAt(i));
            } else {
                char c = s.charAt(i);
                if (st.isEmpty()) {
                    return false;
                } else {
                    if (c == ')') {
                        if (st.peek() != '(')
                            return false;
                    } else if (c == ']') {
                        if (st.peek() != '[')
                            return false;
                    } else {
                        if (st.peek() != '{')
                            return false;
                    }
                    st.pop();
                }
            }
            i++;
        }
        return st.isEmpty();
    }

    boolean isLeftParent(char c) {
        switch (c) {
            case '(': return true;
            case '[': return true;
            case '{': return true;
            default: return false;
        }
    }
}