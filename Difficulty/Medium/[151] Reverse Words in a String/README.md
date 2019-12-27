# 问题描述

给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：

```bash
输入: "the sky is blue"
输出: "blue is sky the"
```

示例 2：

```bash
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
```

示例 3：

```bash
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
```

说明：

- 无空格字符构成一个单词。
- 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
- 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

进阶：

请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。

# 方法

这题没啥技巧的，python实现很简单，C++实现要复杂一些，注意一个坑，当你用size_t来表示长度时，如果是递减的，判断条件为大于等于0，那么将会一直循环，换成int就没问题了。