# 问题描述

给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

```bash
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

示例：

<img src="assets/116_sample.png" alt="img" style="zoom:50%;" /> 

```bash
输入：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

输出：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}

解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
```

提示：
- 你只能使用常量级额外空间。
- 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

# 方法

这道题主要有三种方法。最直观的应该就是使用BFS，对每一层的结点进行从左到右的连接，不过题目要求常数空间，用BFS不符合，第二种方法则是递归求解，递归函数有两个结点，一个左节点，一个右节点，进入函数，将左结点的下一个结点连接为有右节点，然后进入条件判断，如果它们的孩子不为空，左节点的左子树和左节点的右子树进入递归函数，左节点的右子树和右节点的左子树进入递归函数，右节点的左子树和右节点的右子树进入递归函数。第三种方法很是巧妙，也最喜欢，有点DFS+BFS的味道，假设上层已经连好了，可以根据上层连好的结点来连下一层的，比如，对于上层的第一个结点，只需要将它的左孩子和右孩子相连，以及它的右孩子与它的下一个结点的左孩子相连，然后进入下一个结点，继续同样的操作。