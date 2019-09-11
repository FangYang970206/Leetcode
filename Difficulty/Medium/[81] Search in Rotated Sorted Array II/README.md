# 问题描述

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

# 例子

```bash
输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
```

进阶:

- 这是搜索旋转排序数组的延伸题目，本题中的nums可能包含重复元素。
- 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

# 方法

依然采用二分查找，由于是旋转排序数组，不能采用常规方法来求，得到mid值后，要么mid右边是有序的，要么mid左边是有序的，根据这个特性，然后比较target进行区间的选取，对于mid，left，right三个索引指向的值相等，则需要将left加1，right减1，因为这个时候无法确定区间的有序性。

```c++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] == nums[left] && nums[mid] == nums[right])
                {left++; right--;}
            else if (nums[left] <= nums[mid]){
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }else{
                if(nums[right] >= target && target > nums[mid]) left = mid + 1;
                else right = mid - 1; 
            }
        }
        return false;
    }
};
```
