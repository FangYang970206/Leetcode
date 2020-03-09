# 问题描述

给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1:
 
```bash
输入: [5,7]
输出: 4
```

示例 2:

```bash
输入: [0,1]
输出: 0
```

# 方法

这题我的方法是根据每低位的bit的出现频率来做的，最低位每两个会出现0，于此类推。去掉低位的0，最后和区间的左边相与得到结果。

看到别人的解答，别样的想法：
1. 最后一位（奇数和偶数）为0。
2. 当m不等于n, 存在至少一个奇数和一个偶数，所以最后一位为0.
3. 让m和n往右移动一位。

重读做1，2，3，直到m等于n，使用一个因子记录迭代时间。

```java
public class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        if(m == 0){
            return 0;
        }
        int moveFactor = 1;
        while(m != n){
            m >>= 1;
            n >>= 1;
            moveFactor <<= 1;
        }
        return m * moveFactor;
    }
}
```