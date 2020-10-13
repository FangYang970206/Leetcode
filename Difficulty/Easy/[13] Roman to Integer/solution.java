class Solution {
    public HashMap<String, Integer> createDict() {
        HashMap<String, Integer> map = new HashMap<>() {
            {
                put("M", 1000);
                put("CM", 900);
                put("D", 500);
                put("CD", 400);
                put("C", 100);
                put("XC", 90);
                put("L", 50);
                put("XL", 40);
                put("X", 10);
                put("IX", 9);
                put("V", 5);
                put("IV", 4);
                put("I", 1);
            }
        };
        return map;
    }

    public int romanToInt(String s) {
        HashMap<String, Integer> map = createDict();
        int len = s.length(), res = 0, i = 0;
        while (i < len){
            if (i+1 < len) {
                String tmp = s.substring(i, i+2);
                if (map.containsKey(tmp)) {
                    res += map.get(tmp);
                    i += 2;
                } else {
                    res += map.get(s.substring(i, i+1));
                    i += 1;
                }
            } else {
                res += map.get(s.substring(i, i+1));
                i += 1;
            }
        }
        return res;
    }
}


// faster
class Solution2 {
    public int romanToInt(String s) {
        int sum = 0;
        int preNum = getValue(s.charAt(0));
        for(int i = 1;i < s.length(); i ++) {
            int num = getValue(s.charAt(i));
            if(preNum < num) {
                sum -= preNum;
            } else {
                sum += preNum;
            }
            preNum = num;
        }
        sum += preNum;
        return sum;
    }
    
    private int getValue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
}