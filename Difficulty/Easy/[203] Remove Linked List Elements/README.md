# 问题描述

删除链表中等于给定值 val 的所有节点。

示例:

```bash
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
```

# 方法

这题主要需要在头部加入一个哨兵结点，不让当val出现在头部时，会不好处理。