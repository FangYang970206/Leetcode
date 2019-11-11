# 问题描述

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:
```bash
输入: "A man, a plan, a canal: Panama"
输出: true
```

示例 2:
```bash
输入: "race a car"
输出: false
```

# 方法

检测回文字符串，很容易想到使用双指针，一个指针指向头部，一个指向尾部，往中间递进，碰到非数字字母，移动一位。我的解决方案没有使用字符的函数，推荐看下面：

```c++
bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { 
        while (! isalnum(s[i]) && i < j) i++;
        while (! isalnum(s[j]) && i < j) j--;
        if (toupper(s[i]) != toupper(s[j])) return false;
    }
    return true;
}
```

```python
def isPalindrome(self, s):
    l, r = 0, len(s)-1
    while l < r:
        while l < r and not s[l].isalnum():
            l += 1
        while l <r and not s[r].isalnum():
            r -= 1
        if s[l].lower() != s[r].lower():
            return False
        l +=1; r -= 1
    return True
```