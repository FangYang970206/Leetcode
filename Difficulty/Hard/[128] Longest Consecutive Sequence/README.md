# 问题描述

给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:
```bash
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
```

# 方法

我的方法是用vector构造一个set，利用set内部是红黑树，已排好序，然后遍历set，求最大连续序列，然后构造set需要消耗O(nlogn)的复杂度，所以不符合要求。

看了discuss, [StefanPochmann的solution](https://leetcode.com/problems/longest-consecutive-sequence/discuss/41057/Simple-O(n)-with-Explanation-Just-walk-each-streak)很有意思，就在python的solution中，很好懂，检测的当前数的前一位在不在，如果不在，就开始计数, 这是因为如果前一位在的话，当前的数之前就计算过，这样就可以避免重复计算，然而开始的时候还是用到了set，构造set需要O(nlogn), 判断是否在set其实是logn, 遍历也是O(nlogn)。

更有趣的是下面的版本, 来自[mzchen的solution](https://leetcode.com/problems/longest-consecutive-sequence/discuss/41088/Possibly-shortest-cpp-solution-only-6-lines.)：
```c++
int longestConsecutive(vector<int> &num) {
    unordered_map<int, int> m;
    int r = 0;
    for (int i : num) {
        if (m[i]) continue;
        r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
    }
    return r;
}
```
利用哈希表记录边界信息，对于每一个新元素i，它有四种情况：

- i-1和i+1都不在
- 一种是i-1在，i+1也在
- 只有i-1在
- 只有i+1

这里的i-1和i+1指的是相邻连续的左边元素和右边元素，更新边界的值则是通过m[i - m[i - 1]]和m[i + m[i + 1]], 分别对应左边界和右边界，最好在纸上画一画更好理解。
`m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1`涵盖了四种情况，如果相邻连续的左边元素和右边元素都不存在，m[i + 1]和m[i - 1]都为0，m[i - m[i - 1]]和m[i + m[i + 1]]也等于m[i], m[i]等于1，如果相邻连续的左边元素和右边元素都存在，边界值需要更新，等于左右元素的边界值相加再加1，然后更新边界，第3，4情况类似。这种方法真正地达到O(n)。