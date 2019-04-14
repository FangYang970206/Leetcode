# 问题描述
给定一个字符串s，找出s中最长的回文子串。可以假设s的最大长度为1000。

# 例子
```bash
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Input: "cbbd"
Output: "bb"
```

# 方法
我的原始方法是暴力搜索，两个循环确定左右索引$i,j$，判断中间$[i, j)$代表的字符串是否是回文，与最大回文比较，长就替换，时间复杂度太高$O(n^3)$.
C++运行时间超时。还是来欣赏好的方法吧！

# 更好的方法
方法一：以当前索引为中间，往外扩张判断字符串是否为回文数，不符合回文数退出内层循环，取最大字符串，time = 932 ms。
ref: https://leetcode.com/problems/longest-palindromic-substring/discuss/2954/Python-easy-to-understand-solution-with-comments-(from-middle-to-two-ends).这个方法占用了O(n)的空间，可以使用$[begin, end)$降至$O(1)$.
```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ''
        for i in range(len(s)):
            odd  = self.palindromeAt(s, i, i)
            even = self.palindromeAt(s, i, i+1)
            res = max(res, odd, even, key=len)
        return res
        
    def palindromeAt(self, s, l, r):    
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l+1:r]
```

方法二: 这种方法比较巧妙，当想s增加一个字符时，最长的回文数可能加1，加2或者不动，所以处理的方式就是建立一个最长回文数长度maxLen，跟踪这个长度，当前索引为i，判断$s[i-maxLen-1:i+1]$(对应'abba')和$s[i-maxLen:i+1]$(对应'aba')是否为回文数，对最大maxlen加上对应的长度。Times = 88ms
ref: https://leetcode.com/problems/longest-palindromic-substring/discuss/2925/Python-O(n2)-method-with-some-optimization-88ms.
```python
class Solution:
    def longestPalindrome(self, s):
        if len(s)==0:
        	return 0
        maxLen=1
        start=0
        for i in xrange(len(s)):
        	if i-maxLen >=1 and s[i-maxLen-1:i+1]==s[i-maxLen-1:i+1][::-1]:
        		start=i-maxLen-1
        		maxLen+=2
        		continue

        	if i-maxLen >=0 and s[i-maxLen:i+1]==s[i-maxLen:i+1][::-1]:
        		start=i-maxLen
        		maxLen+=1
        return s[start:start+maxLen]
```
方法三：这个方法非常巧妙，时间复杂度达到$O(n)$，这个方法的名字是Manacher‘s Algorithm，也叫马拉车方法，方法建立了一个数组，数组第i个元素表示以 i 为中心的最长回文的半径，利用回文数的对称性，在一个大的回文数后面的索引可以利用对称性映射前面而大大简化计算。算法细节描述请参考https://segmentfault.com/a/1190000008484167?utm_source=tag-newest，讲得非常好，以下代码来自http://www.cnblogs.com/grandyang/p/4475985.html。
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        string t = "$#";
        for (int i = 0; i < s.size(); ++i){
            t += s[i];
            t += '#';
        }
        vector<int> p(t.size(), 0);
        int mx = 0, id = 0, resLen = 0, resCenter = 0;
        for (int i = 1; i < t.size(); ++i){
            p[i] = mx > i ? min( p[2 * id - i], mx - i ) : 1;
            while (t[ i + p[i] ] == t[ i - p[i] ]) ++p[i];
            if (mx < i + p[i]){
                mx = i + p[i];
                id = i;
            }
            if (resLen < p[i]){
                resLen = p[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - resLen) / 2, resLen - 1);
    }
    
};
```