# 问题描述
返回haystack中needle的第一次出现的索引，如果needle不是haystack的一部分，返回-1。如果needle为空，返回0；

# 例子
```bash
Input: haystack = "hello", needle = "ll"
Output: 2

Input: haystack = "aaaaa", needle = "bba"
Output: -1
```

# 方法
我用的暴力搜索的方法，先判断是否为空，然后判断needle的长度是否大于haystack的长度。然后开始搜索，两层循环，外层是haystack的循环，内层是needle，依次判断片段是否相等，不相等直接退出内层循环。

# 更好的方法
有一个优化没有考虑到，那就是外层循环可以是`haystack.size - needle.size`.
**python更简短的方法**: 使用str.find或者str.index函数直接返回索引，速度一样，代码极其简短。
ref: https://leetcode.com/problems/implement-strstr/discuss/12814/My-answer-by-Python

**更有快速的方法：KMP算法**
下面给出来自清华大学邓俊辉数据结构课程的C++版实现：
```c++
int* buildNext(char* P) { //构造模式串P的next表
	size_t m = strlen(P), j = 0; //“主”串指针
	int* N = new int[m]; //next表
	int t = N[0] = -1; //模式串指针
	while (j < m - 1)
		if (0 > t || P[j] == P[t]) { //匹配
			j++; t++;
			N[j] = t; //此句可改进...
		}
		else //失配
			t = N[t];
	return N;
}

int match(char* P, char* T) {  //KMP算法
	int* next = buildNext(P); //构造next表
	int n = (int)strlen(T), i = 0; //文本串指针
	int m = (int)strlen(P), j = 0; //模式串指针
	while (j < m  && i < n) //自左向右逐个比对字符
		/*DSA*/ {
		if (0 > j || T[i] == P[j]) //若匹配，或P已移出最左侧（两个判断的次序不可交换）
		{
			i++;  j++;
		} //则转到下一字符
		else //否则
			j = next[j]; //模式串右移（注意：文本串不用回退）
	}
	delete[] next; //释放next表
	return i - j;
}
```
