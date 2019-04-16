# 问题描述
字符串“PAYPALISHIRING”在给定行数上以之字形书写，如下所示:
```bash
P   A   H   N
A P L S I I G
Y   I   R
```
然后逐行读取:“PAHNAPLSIIGYIR”编写代码，该代码将接受一个字符串，并在给定行数的情况下进行转换:
```bash
string convert(string s, int numRows);
```
# 例子
```bash
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
```

# 方法
首先审好题，观看结果解释，是以旋转翻转Z的形状进行排列的，根据这一性质，就可以找到字符按周期排列，生成对应行数的vector<string>, 存放每一行的字符，最后相加起来。