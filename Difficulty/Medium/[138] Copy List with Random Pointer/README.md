# 问题描述

给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深拷贝。 

**示例**：

![img](assets/1470150906153-2yxeznm.png)

```bash
输入：
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

解释：
节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
```

**提示：**

1. 你必须返回**给定头的拷贝**作为对克隆列表的引用。

# 方法

这题我采用的是two-pass的方法，第一次遍历链表，构造出深拷贝的链表，深拷贝所有的random都为空，不过我是用unordered_map对原始链表进行索引(key是Node，value是index），用一个vector对深拷贝的链表Node进行存储，第二次遍历原链表的时候，原链表的random可以根据unordered_map寻找到对应的Node所在的index，然后由于我们存储了新拷贝的Node，根据vector和index就可以知道新拷贝的结点的random该指向哪里。