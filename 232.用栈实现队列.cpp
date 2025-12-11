/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<vector> 
#include<algorithm>  
#include<stack>
using namespace std; 
// @lc code=start
class MyQueue {
public:
    // 创建两个栈,输入栈和输出栈
    stack<int> inStack, outStack; 

    // 辅助函数,将输入栈中的元素压入输出栈
    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top()); 
            inStack.pop(); 
        }
    } 


    void push(int x) {
        inStack.push(x); 
    }
    
    int pop() {
        if (outStack.empty()) { 
            in2out(); 
        } 
        int x = outStack.top();  
        outStack.pop(); 
        return x; 
    }
    // 查找,直接返回输出栈的栈顶元素
    int peek() { 
        if (outStack.empty()) {
            in2out(); 
        } 
        return outStack.top(); 
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

