# 问题描述

给定n个非负整数，表示一个高程图，其中每个条的宽度为1，计算它在雨后能够截留多少水。

# 例子

![img](assets/rainwatertrap.png)

```bash

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

```

# 方法

采用双指针, 基于一种观察，两边会往内由小变大，并且相邻的两个由最大的那个决定它的值。具体实现请看代码：

```c++
int trap(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ :r--];
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}
```