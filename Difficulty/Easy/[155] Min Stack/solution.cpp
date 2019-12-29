/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
private:
    stack<int> S;
    vector<int> vec;
    int minimum;

public:
    /** initialize your data structure here. */
    MinStack() : minimum(INT_MAX){
        
    }
    
    void push(int x) {
        S.push(x);
        minimum = min(x, minimum);
        vec.push_back(minimum);
    }
    
    void pop() {
        vec.pop_back();
        S.pop();
        if (! vec.empty())
            minimum = vec.back();
        else
            minimum = INT_MAX;
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return minimum;
    }
};

class MinStack {
private:
    stack<int> S;
    unordered_map<int, vector<int>> umm;
    int minimum;

public:
    /** initialize your data structure here. */
    MinStack() : minimum(INT_MAX){
        
    }
    
    void push(int x) {
        S.push(x);
        minimum = min(x, minimum);
        umm[x].push_back(minimum);
    }
    
    void pop() {
        if (umm[S.top()].size() != 1)
            umm[S.top()].pop_back();
        else
            umm.erase(S.top());
        S.pop();
        if (! S.empty())
            minimum = umm[S.top()].back();
        else
            minimum = INT_MAX;
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return minimum;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

