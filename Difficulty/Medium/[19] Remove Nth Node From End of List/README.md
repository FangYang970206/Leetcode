# 描述 
给定一个链表，从链表末尾删除第n个节点并返回其头部。给定n总是有效的。

# 例子

```bash
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
```

# 方法
方法1：two-pass, 由于不知道链表的长度，所以第一个pass，遍历整个链表求得链表长度，第二个pass根据链表长度，删除倒数第n个结点。（python: 48ms, 13.2Mb  C++: 8ms, 8.6Mb)

方法2：one-pass，使用双指针，两个指针在链表同时移动，它们之间的距离为n，所以当前面一个指针指向NULL时，则后面那个指针就指向要删除的结点了。(C++: 0ms, 8.5Mb)

