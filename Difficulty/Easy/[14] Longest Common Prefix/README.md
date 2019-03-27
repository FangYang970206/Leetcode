# 问题描述
给一个字符串的列表，找出所有字符串中相同前缀最长的字符。

# 我的方法
- 开始审题审错了，以为是求所有字符串中最长的相同的字符串片段，当然，这种更难，最后一节给出具体实现。

本题的方法就很简单了，对所有字符串从第一个元素开始比较，看是否相同，直到不同就return前面相同的字符就可以了。(C++实现8ms, 速度超过98.85%的人， 内存占用少于99.82%的人)

# 遇到的问题
在写循环时，循环内部变化的量别在循环内初始化，会引起多次初始化，导致结果错误。


# 找到字符串列表中最长的相同字符串片段（这个更强）
```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        if len(strs) == 1:
            return strs[0]
        def getCommonPrefixForTwoStr(str1, str2):
            common_prefix = set()
            str1_len = len(str1)
            str2_len = len(str2)
            for i in range(str1_len):
                temp1 = i
                for j in range(str2_len):
                    if str2[j] == str1[temp1]:
                        common_prefix.add(str1[temp1])
                        common_prefix.add(str1[i:temp1+1])
                        if temp1 == str1_len - 1:
                            common_prefix.add(str1[i:])
                            temp1 = 0
                        else:
                            temp1 += 1
            return common_prefix
        CommonPrefixAllStr = getCommonPrefixForTwoStr(strs[0], strs[1])
        for i in range(1, len(strs)-1):
            CommonPrefix = getCommonPrefixForTwoStr(strs[i], strs[i+1])
            CommonPrefixAllStr.intersection_update(CommonPrefix)
            if not CommonPrefixAllStr:
                return ""
        
        longestCommonPrefix = ""
        longest_len = 0
        for prefix in CommonPrefixAllStr:
            if len(prefix) > longest_len:
                longest_len = len(prefix)
                longestCommonPrefix = prefix
        return longestCommonPrefix
```
