# 问题描述

设计一个支持以下两种操作的数据结构：
```bash
void addWord(word)
bool search(word)
```
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:
```bash
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
```
说明:

- 你可以假设所有单词都是由小写字母 a-z 组成的。

# 方法

这题需要构建一个前缀树题，在前缀树上进行字符串搜索，不同的是此题加入了'.',当遇到'.'，对当前结点的26个子节点都要进行遍历，有符合条件的输出为True，search过程使用递归。