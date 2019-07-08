# 问题描述

给定两个表示为字符串的非负整数num1和num2，返回也表示为字符串的num1和num2的乘积。

Note:
- num1和num2的长度都小于110。
- num1和num2都只包含0-9。
- 除了数字0本身之外，num1和num2都不包含任何前导零。
- 您不能使用任何内置的BigInteger库或直接将输入转换为integer。

# 例子

```bash
Input: num1 = "2", num2 = "3"
Output: "6"

Input: num1 = "123", num2 = "456"
Output: "56088"
```

# 方法

首先倒序进行相乘，需要明白一个特性，num1[i]和num2[j]一定会出现在res[i+j+1]和res[i+j], 其中res[i+j+1]可以理解为两个数相乘的个位，而res[i+j]可以理解为两个数相乘的十位。