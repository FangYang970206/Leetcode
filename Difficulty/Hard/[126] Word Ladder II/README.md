# 问题描述

给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

    1. 每次转换只能改变一个字母。
    2. 转换过程中的中间单词必须是字典中的单词。

说明:

- 如果不存在这样的转换序列，返回一个空列表。
- 所有单词具有相同的长度。
- 所有单词只由小写字母组成。
- 字典中不存在重复的单词。
- 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

示例 1:
```bash
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
```

示例2:
```bash
输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []

解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
```

# 方法

这一题很难，自己写的方法超时了。主要参考了[wang](https://leetcode-cn.com/problems/word-ladder-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-3-3/)和[sohammehta](https://leetcode.com/problems/word-ladder-ii/discuss/40434/C++-solution-using-standard-BFS-method-no-DFS-or-backtracking/191262)

wang介绍了多种方法，主要是bfs和dfs，还包括两者的混合使用，以及双向混合使用，dfs会与bfs一起使用，通过bfs找到邻居，然后dfs根据邻居进行搜索，通过回溯的办法看是否能找到通过终点的路径，优化的方法有记录最短路径的长度，大于该长度返回，还有记录单词的高度，如果下一次还出现该单词，比较高度得到，如果高度大则可以不进行接下来的搜索。bfs则是直接记录所有路径，如果出现符合的，完成当层的搜索，下面就可以不用进行了，较为简单，我的solution加了bfs的方法，bfs要加上一个visited的哈希表，用来记录已访问的单词，需要把已出现的单词从wordList里面去掉，已提高搜索效率。最后一种双向的是有两个出发点，一个是起点单词，一个是终点单词，同时搜索，直到它们相遇，这里的同时是看谁的邻居少，谁先搜索，这样就可以减少计算量，并且两路出发可以将时间复杂度从$k^n$变为$k^(n/2) + k^(n/2)$.

sohammehta就是简单的bfs，更加浅显易懂。