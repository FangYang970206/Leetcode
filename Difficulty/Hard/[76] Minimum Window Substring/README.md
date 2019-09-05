# 问题描述

给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

# 例子

```bash
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
```

说明：

- 如果 S 中不存这样的子串，则返回空字符串 ""。
- 如果 S 中存在这样的子串，我们保证它是唯一的答案。


# 方法

这题我想到的方法超时了, 不是好的解法，在讨论中看到下面的解法，非常巧妙。

先说说大体思路：
1. 使用双指针begin和end，代表滑动窗口的起始与末尾。（ps: 我自己写的解法也用到了双指针，但是将双指针之间的字符拷贝出来进行判断，太花费时间了）
2. 通过移动end指针来找到一个有效的窗口
3. 当窗口有效时，移动begin指针来找到更小的窗口

具体看下面的代码注释：

```c++
string minWindow(string s, string t) {
    vector<int> map(128, 0); //由于字符的特殊性，只在较小范围，所以用数组来代替哈希表，内存小不说，还要快上许多
    for(auto c : t) ++map[c]; //对t中的字符进行计数
    int begin = 0, end = 0, min_len = INT_MAX, min_begin = 0, counter = t.size(), s_size = s.size();
    while (end < s_size) {
        if (map[s[end]] > 0) //如果s中的字符在t中，递减counter
            --counter;
        --map[s[end]]; //同时递减数组中字符的数量，如果s中字符不在t中，m[s[end]]将是负数
        ++end;         //递加end
        while (counter == 0){ // 当窗口有效时，移动begin指针来找到更小的窗口
            if (end - begin < min_len){ //与最小窗口相比，找到更小的窗口
                min_begin = begin;
                min_len = end - begin;
            }
            map[s[begin]]++;  //这一步可以抵消前面的end的递减, 不在t中的字符始终不会大于0，而且即使出现出现在t的字符小于0（意味着有多个），这一步还可以通过下面的判断消除冗余
            if (map[s[begin]] > 0) // 出现大于0, 说明窗口不在有效，计数递加
                counter++;
            ++begin;
        }
    } 
    if (min_len != INT_MAX)
        return s.substr(min_begin, min_len);
    return "";
}
```