# 问题描述

给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。

下图是字符串 s1 = "great" 的一种可能的表示形式。

```bash
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
```
在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。

例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。
```bash
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
```
我们将 "rgeat” 称作 "great" 的一个扰乱字符串。

同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。

```bash
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
```

我们将 "rgtae” 称作 "great" 的一个扰乱字符串。

给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。

# 例子

```bash
输入: s1 = "great", s2 = "rgeat"
输出: true

输入: s1 = "abcde", s2 = "caebd"
输出: false
```

# 方法

清晰的解释：

```bash
why "abcde", is NOT a scramble of "caebd". 
a | bcde --> 'a' not anagram of 'c' nor 'd'
ab | cde --> ab not anagram of ca nor of bd
abc | de --> abc not anagram of cae nor of ebd
abcd | e --> abcd not anagram of caeb nor of aebd
```

方法是通过切分字符串的每一种分法，计算对应的字符串是否计数为0，如果计数不为0，则返回false. 


