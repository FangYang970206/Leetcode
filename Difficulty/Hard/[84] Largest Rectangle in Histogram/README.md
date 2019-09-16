# 问题描述

给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

![img](assets/histogram.png)

以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 `[2,1,5,6,2,3]`。

![img](assets/histogram_area.png)

图中阴影部分为所能勾勒出的最大矩形面积，其面积为 `10` 个单位。

# 例子

```bash
输入: [2,1,5,6,2,3]
输出: 10
```

# 方法

这道题的思路是使用栈（使用vector替代），方法很是巧妙，对于连续增加的height，直接push back到栈中，而当出现高度下降的时候，则开始循坏计算矩形长度，每次pop back一个height，如果height小于当前高度，则退出循环，继续下一个高度.

```c++
int largestRectangleArea(vector<int> &height) {
    int ret = 0;
    height.push_back(0);
    vector<int> index;

    for(int i = 0; i < height.size(); i++)
    {
        while(index.size() > 0 && height[index.back()] >= height[i])
        {
            int h = height[index.back()];
            index.pop_back();

            int sidx = index.size() > 0 ? index.back() : -1;
            if(h * (i-sidx-1) > ret)
                ret = h * (i-sidx-1);
        }
        index.push_back(i);
    }

    return ret;
}
```
