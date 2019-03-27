# Leetcode
This repo records my leetcode solutions. Every problem contains python and cpp implementation with readme_zh.

# Features
Two categorys: different diffculty and topics. Thank for [**vs code extension for leetcode**](https://github.com/jdneo/vscode-leetcode).

diffculty:
- easy
- medium
- hard

topics:
- Array
- Backtracking
- Binary Indexed Tree
- Binary Search
- Binary Search Tree
- BIt Manipulation
- Breadth First Search
- Depth First Search
- Design
- Divide And Conquer
- Dynamic Programing
- Graph
- Greedy
- Hash Table
- Heap
- Linked List
- Map
- Math
- Queue
- Reservoir Sample
- Segment Tree
- Sort
- Stack
- String
- Topological Sort
- Tree
- Trie
- Two Pointers
- Union Find
- Unknown

# Example
Problem20:Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. 

C++ version(faster than 100% of cpp submissions and memory usage beats 99.62% of cpp submissions):
```C++
#include <stack>

bool isContainingTargetParenthese(const string& s, const vector<string>& t_p) {
	for (auto it = t_p.begin(); it != t_p.end(); it++) {
		if (s == *it)
			return true;
	}
	return false;
}

string twoCharToString(char c1, char c2) {
	string s = "xx";
	s[0] = c1;
	s[1] = c2;
	return s;
}

class Solution {
public:

	bool isValid(string s) {
		if (s.empty())
			return true;
		if (s.size() % 2 != 0)
			return false;
		vector<string> match_parenthese = { "()", "{}", "[]" };
		if (s.size() == 2) {
			return isContainingTargetParenthese(s, match_parenthese);
		}
		vector<string> mismatch_parenthese = { "(]", "(}", "[)", "[}", "{)", "{]" };
		stack<char> stack1;
		stack<char> stack2;
		for (int i = 0; i < s.size(); i++)
			stack1.push(s[i]);
		char temp1 = stack1.top();
		stack1.pop();
		char temp2 = stack1.top();
		stack1.pop();
		while (!stack1.empty()) {
			if (isContainingTargetParenthese(twoCharToString(temp2, temp1), match_parenthese)) {
				if (stack2.empty()) {
					temp1 = stack1.top();
					stack1.pop();
					temp2 = stack1.top();
					stack1.pop();
				}
				else {
					temp1 = stack2.top();
					stack2.pop();
					temp2 = stack1.top();
					stack1.pop();
				}
			}
			else if (isContainingTargetParenthese(twoCharToString(temp2, temp1), mismatch_parenthese))
				return false;
			else {
				stack2.push(temp1);
				temp1 = temp2;
				temp2 = stack1.top();
				stack1.pop();
			}
		}
		if (stack2.empty() && isContainingTargetParenthese(twoCharToString(temp2, temp1), match_parenthese))
			return true;
		else
			return false;
	}
};
```
python version:
```python
class Solution:
    def isValid(self, s: str) -> bool:
        if not s:
            return True
        if len(s) % 2 != 0:
            return False
        parenthese = ['()', '{}', '[]']
        if len(s) == 2:
            return s in parenthese
        from collections import deque
        mis_parenthese = ['[)', '[}', '(]', '(}', '{]', '{)']
        deque1 = deque()
        deque2 = deque()
        for elem in s:
            deque1.append(elem)
        temp1 = deque1.pop()
        temp2 = deque1.pop()
        while(deque1):
            if (temp2+temp1) in parenthese:
                if deque2:
                    temp1 = deque2.pop()
                    temp2 = deque1.pop()
                else:
                    temp1 = deque1.pop()
                    temp2 = deque1.pop()
            elif (temp2+temp1) in mis_parenthese:
                return False
            else:
                deque2.append(temp1)
                temp1 = temp2
                temp2 = deque1.pop()
            
        if (not deque2) and (temp2+temp1) in parenthese:
            return True
        else:
            return False
```



