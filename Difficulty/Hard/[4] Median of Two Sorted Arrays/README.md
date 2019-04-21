# 问题描述
有两个大小分别为m和n的排序数组nums1和nums2。求两个排序数组的中值。
总的运行时复杂度应该是O(log(m+n))。您可以假设nums1和nums2不能同时为空。
# 例子
```bash
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
```
# 方法
建立一个新的列表，长度是输入两个列表长度之和，两个列表依次倒序比较，大的放入新列表的相应位置，当其中至少一个列表为空时，退出循环，还得将那个列表为空最后pop出的数与非空列表进行比较，找到小于那个书即终止，将剩余的数赋值给新列表。

方法还可以进一步优化，不需要将新的list全部填满，判断列表长度之和是否为偶数，是则新列表长度为2，否则长度为1，只存储中间的值，存储完即返回，后面的值无需比较，这种方法在大规模数据下更快占用内存更小。