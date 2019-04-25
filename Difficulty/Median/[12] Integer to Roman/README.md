# 描述 
罗马数字由七种不同的符号表示:I、V、X、L、C、D和M。

```bash
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

例如，2用罗马数字写成`II`，两个1相加。十二被写成`XII`，也就是`X+II`。27被写成`XXVII`，也就是`XX+V+II`。

罗马数字通常从左到右由大到小书写。然而，4的数字不是`IIII`。4写成了`IV`，因为1在5之前，所以减4。同样的原理也适用于数字9，也就是`IX`。

减法有六种应用:
- I can be placed before V (5) and X (10) to make 4 and 9. 
- X can be placed before L (50) and C (100) to make 40 and 90. 
- C can be placed before D (500) and M (1000) to make 400 and 900.

# 例子

```bash
Input: 3
Output: "III"

Input: 4
Output: "IV"

Input: 9
Output: "IX"

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

# 方法
依次对num除以1000，100，10，1，根据商来判断转换的字符，特别是当商等于4或者9时，模式固定。