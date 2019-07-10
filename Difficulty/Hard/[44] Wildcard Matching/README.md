# 问题描述

给定一个输入字符串s和一个模式p，实现通配符模式匹配，并支持'?'和'*'。

- ”?匹配任何单个字符。'*'匹配任何字符序列(包括空序列)。

匹配应该覆盖整个输入字符串(而不是部分)。

- s可以是空的，并且只包含小写字母a-z。
- p可以是空的，并且只包含小写字母a-z和类似的字符?或*。

# 例子

```bash

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Input:
s = "acdcb"
p = "a*c?b"
Output: false

```

# 方法

来自于http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size(), i = 0, j = 0, sTrack = -1, pTrack = -1;
        while (i < sLen){
            // 字符相等则s和p的索引都自加1
            if ((s[i] == p[j]) || (p[j] == '?')) {i++; j++; continue;}
            // 如果碰到*号，记录下出现*的位置pTrack, 以及出现*号时对应的s的索
            // 引sTrack, s的索引不动，p的索引自加1
            if (p[j] == '*') {sTrack=i; pTrack=j++; continue;}
            // 进行到这一步意味着上面两步都没有成功，这时候如果PTrack不大于0，
            //意味着没有出现*号, 不匹配则返回false, 如果大于0, 则意味着出现了
            // *号，就可能会出现"acdcb"和"a*cb"这种情况——p中的c匹配导s的第
            // 一个c，这时候需要跳过之前匹配的c，慢慢递加匹配下一个c, 然后继续
            // 匹配（上面的两个条件），如果无法匹配，再跳过第二个c...,这种由短至长的匹配也是程序正确的重要原因。
            if (pTrack >= 0) {j = pTrack+1; i=++sTrack; continue;} //精髓所在
            return false;
        }
        while(p[j] == '*') j++; //p可能存在多余的
        return j==pLen;
    }
};
```