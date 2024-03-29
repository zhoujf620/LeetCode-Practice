/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (40.83%)
 * Likes:    2608
 * Dislikes: 272
 * Total Accepted:    410.1K
 * Total Submissions: 1M
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class MinStack {
public:
    vector<pair<int, int>> stack_;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        int min_num;
        if(stack_.empty())
            min_num = x;
        else
            min_num = min(x, stack_.back().second);
        stack_.push_back(make_pair(x, min_num));
    }
    
    void pop() {
        stack_.pop_back();
    }
    
    int top() {
        return stack_.back().first;
    }
    
    int getMin() {
        // if (stack_.empty())
        //     return -1;
        return stack_.back().second;
    }
};


// class MinStack {
// private:
//     vector<int> stack;
//     int cur_min;

// public:
//     /** initialize your data structure here. */
//     MinStack() {

//     }
    
//     void push(int x) {
//         if (stack.empty()) {
//             cur_min = x;
//             stack.push_back(0);
//         }
//         else {
//             int diff = x - cur_min;
//             stack.push_back(diff);
//             if (diff < 0) cur_min = x;
//         }
//     }
    
//     void pop() {
//         int diff = stack.back();
//         if (diff < 0) cur_min -= diff;
//         stack.pop_back();
//     }
    
//     int top() {
//         int diff = stack.back();
//         return cur_min + diff;
//     }
    
//     int min() {
//         return cur_min;
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

