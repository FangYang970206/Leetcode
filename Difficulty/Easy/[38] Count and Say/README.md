# 描述

原题描述不清晰，以下描述很好：
初始值第一行是 1。
第二行读第一行，1 个 1，去掉个字，所以第二行就是 11。
第三行读第二行，2 个 1，去掉个字，所以第三行就是 21。
第四行读第三行，1 个 2，1 个 1，去掉所有个字，所以第四行就是 1211。
第五行读第四行，1 个 1，1 个 2，2 个 1，去掉所有个字，所以第五航就是 111221。
第六行读第五行，3 个 1，2 个 2，1 个 1，去掉所以个字，所以第六行就是 312211。
然后题目要求输入 1 - 30 的任意行数，输出该行是啥。
以上描述来自于https://leetcode.com/problems/count-and-say/discuss/16015/Please-change-the-misleading-description

# 方法

防止n==1处理在循环加上一个判断条件，先判断n==1和n==2，然后进行循环，外循环为n的次数（减去前面判断的两次），内循环遍历s，temp存储当前字符串，c代表前一个字符，num是对前一个字符的计数，分三种情况，当c存在且遍历当前s中的元素等于c，num进行加1，如果不等于，说明该加上str(num) + c了，重新设置num和c，最后一种情况是初始c为空和num为0，赋相应的初值。

```python
def countAndSay(self, n: int) -> str:
    if n == 1:
        return '1'
    if n == 2:
        return '11'
    s = '11'
    for _ in range(n - 2):
        temp, num, c = '', 0, ''
        for elem in s:
            if c and elem == c:
                num += 1
            elif c and elem != c:
                temp += str(num) + c
                num = 1
                c = elem
            else:
                num = 1
                c = elem
        temp += str(num) + c
        s = temp
    return s
```