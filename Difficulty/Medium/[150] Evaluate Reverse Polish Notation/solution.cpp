/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        int num1, num2;
        for (auto& token : tokens) {
            if (token == "+") {
                getNums(S, num1, num2);
                S.push(num1 + num2);
            }else if (token == "-") {
                getNums(S, num1, num2);
                S.push(num1 - num2);
            }else if (token == "*") {
                getNums(S, num1, num2);
                S.push(num1 * num2);
            }else if (token == "/") {
                getNums(S, num1, num2);
                S.push(num1 / num2);
            }else {
                S.push(stoi(token));
            }
        }
        return S.top();
    }

    void getNums(stack<int>& S, int& num1, int& num2) {
        num2 = S.top();
        S.pop();
        num1 = S.top();
        S.pop();
    }   
};


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s1, s2;
        unordered_set<string> ops {"+", "-", "*", "/"};
        string op, num1, num2;
        for (auto token : tokens)
            s1.push(token);
        while (s1.size() + s2.size() != 1) {
            if (s2.empty()) {
                string op = s1.top();
                s1.pop();
                string num2 = s1.top();
                s1.pop();
                if (ops.find(num2) != ops.end()) {
                    s2.push(op);
                    s2.push(num2);
                    continue;
                }
                string num1 = s1.top();
                s1.pop();
                if (ops.find(num1) != ops.end()) {
                    s2.push(op);
                    s2.push(num2);
                    s2.push(num1);
                    continue;
                }
                s1.push(calculate(num1, num2, op));
            }else {
                op = s1.top();
                s1.pop();
                if (ops.find(op) != ops.end()) {
                    num2 = s1.top();
                    s1.pop();
                    if (ops.find(num2) != ops.end()) {
                        s2.push(op);
                        s2.push(num2);
                    }else{
                        num1 = s1.top();
                        s1.pop();
                        if (ops.find(num1) != ops.end()) {
                            s2.push(op);
                            s2.push(num2);
                            s2.push(num1);
                        }else {
                            s1.push(calculate(num1, num2, op));
                        }
                    }
                }else {
                    num2 = s2.top();
                    s2.pop();
                    if (ops.find(num2) != ops.end()) {
                        num2.swap(op);
                        num1 = s1.top();
                        s1.pop();
                        if (ops.find(num1) == ops.end())
                            s1.push(calculate(num1, num2, op));
                        else{
                            s2.push(op);
                            s2.push(num2);
                            s2.push(num1);
                        }
                    }else{
                        num1 = s2.top();
                        s2.pop();
                        num1.swap(op);
                        if (ops.find(num1) != ops.end())
                            s1.push(calculate(num1, num2, op));
                        else{
                            s2.push(op);
                            s2.push(num2);
                            s2.push(num1);     
                        }
                    }
                }
            }
        }
        return stoi(s1.top());
    }

    string calculate(const string& num1, const string& num2, const string& op) {
        if (op == "+")
            return to_string(stoi(num1) + stoi(num2));
        if (op == "-")
            return to_string(stoi(num1) - stoi(num2));
        if (op == "/")
            return to_string(stoi(num1) / stoi(num2));
        if (op == "*")
            return to_string(stoi(num1) * stoi(num2));
        return "";
    }       
};
// @lc code=end

