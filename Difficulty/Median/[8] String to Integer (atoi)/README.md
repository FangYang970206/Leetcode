# 问题描述
实现将字符串转换为整数的atoi。

函数首先丢弃尽可能多的空白字符，直到找到第一个非空白字符。然后，从这个字符开始，取一个可选的初始正负号，后跟尽可能多的数字，并将它们解释为一个数值。

字符串可以包含构成整数的字符之后的附加字符，这些字符将被忽略，并且对函数的行为没有影响。

如果不能执行有效的转换，则返回一个零值。
# 例子
```bash
Input: "42"
Output: 42

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
```

# 方法
首先判断字符的长度，长度为0，返回0，长度为1，判断是否为数字，不为数字，返回0，还要判断整个str是否都是空格，是则返回0；然后找到第一个不是空格的索引，在这个索引下依次递加查询数字，在查询之前要判断第一个字母是否为负号或者正号，建立了一个符号标志，然后依次生成数字，终止条件是发现字符不是数字，另外，这里为了防止溢出，使用long类型进行数字的计算，在循环的过程中会判断是否超过了整形的最大值，超过返回最大值或者最小值。
