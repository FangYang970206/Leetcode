# 问题描述

给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

# 例子

```bash
输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
```

# 方法

我使用的是较为简单的two-pass方案，通过对当前节点的val与x进行判断，小的放入less_set, 大的放入greater_set，然后再重新遍历一遍链表，依次进行赋值。

下面是one-pass方案，速度快，内存小, 思路使用链表来代替vector,这样在最后阶段进行两次赋值即可完成vector遍历的操作。(来自https://leetcode.com/problems/partition-list/discuss/29185/Very-concise-one-pass-solution):
```c++
ListNode *partition(ListNode *head, int x) {
    ListNode node1(0), node2(0);
    ListNode *p1 = &node1, *p2 = &node2;
    while (head) {
        if (head->val < x)
            p1 = p1->next = head;
        else
            p2 = p2->next = head;
        head = head->next;
    }
    p2->next = NULL;
    p1->next = node2.next;
    return node1.next;
}
```