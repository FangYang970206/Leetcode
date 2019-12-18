# 问题描述

老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

- 每个孩子至少分配到 1 个糖果。
- 相邻的孩子中，评分高的孩子必须获得更多的糖果。

那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

```bash
输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
```

示例 2:

```bash
输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
```

# 方法

这题方法比较巧妙，采用two-pass，一遍顺序，一遍逆序，去两者中的最大值。为什么这样的two-pass, 直观解释可以参考[链接1](https://leetcode-cn.com/problems/candy/solution/candy-cong-zuo-zhi-you-cong-you-zhi-zuo-qu-zui-da-/)或者[链接2](https://leetcode.com/problems/candy/discuss/42794/Simple-O(n)-Java-solution-with-comments/115332)，还有其他解法，one-pass的方法是记录上升的高度和下降的高度，这样就不需要two-pass了，不是很直观，想了解可以参考[链接](https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode/)