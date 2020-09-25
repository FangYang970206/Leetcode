class Solution {
    public String intToRoman(int num) {
        String[] ss = new String[] {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int[] nums = new int[] {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < nums.length; i++) {
            if (num >= nums[i]) {
                int count = num / nums[i];
                while (count-- != 0) res.append(ss[i]);
                num %= nums[i];
            }
        }
        return res.toString();
    }
}