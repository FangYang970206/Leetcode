# 问题描述
合并k排序链表并将其作为一个排序链表返回。分析并描述其复杂性。

# 例子
```bash
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
```

# 方法
用多种方法：可以参考官方的solutionhttps://leetcode.com/problems/merge-k-sorted-lists/solution/ ，很清晰。

官方的分而治之（solution2）更加快速并且占用内存小，我的实现（solution）慢一些，用c++实现后，12ms，11.3Mb。