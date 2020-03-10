# 问题描述

实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

```bash
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true
```

说明:

- 你可以假设所有的输入都是由小写字母 a-z 构成的。
- 保证所有输入均为非空字符串。

# 方法

前缀树的每一个结点有代表一个字符，取决它在父节点的子节点的哪一位，比如它在父节点的第一位就代表'a'字符，第二位代表'b'字符，以此类推。每个节点都有26个子节点，分别代表26个英文字符。插入先判断是否包含当前字符，如果不包含，就要创建新结点，往下以此创建，存在继续向下。查找按照所要查找的字符进行DFS搜索。插入和查找都只有O(m)的时间复杂度，m为字长。