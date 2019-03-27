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