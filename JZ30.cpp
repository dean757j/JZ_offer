/*
JZ30 包含min函数的栈
*/
class Solution {
public:
    stack<int> data, mins;
    void push(int value) {
        data.push(value);
        if (mins.empty() || value < mins.top())
            mins.push(value);
        else
            mins.push(mins.top());
    }
    void pop() {
        data.pop();
        mins.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return mins.top();
    }
};
