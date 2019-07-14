# 问题描述

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

# 例子

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

说明：假设你总是可以到达数组的最后一个位置。

# 方法

采用的是贪婪算法，考虑上面的实例[2, 3, 1, 1, 4], 第一步怎样走更好呢，我们需要越快接近末尾越好，为此考虑局部最优情况，也就是第一步跳跃到的点所能跳跃的最大距离和第一步跳跃的距离之和最远(需要遍历能跳到的数，计算最大偏移量)，每一步最优，恰恰对于这个问题也是全局最优。

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, cur_index = 0;
        while(cur_index != nums.size() - 1){
            if (cur_index + nums[cur_index] >= nums.size() - 1)
                return step + 1;
            int max_shift = 0;
            int sub_optimal_index = 0;
            for (int i = 1; i <= nums[cur_index]; ++i){
                if ((i + nums[i + cur_index]) > max_shift){
                    max_shift = i + nums[i + cur_index];
                    sub_optimal_index = cur_index + i;
                }
            }
            cur_index = sub_optimal_index;
            step++;
        }
        return step;
    }
};
```