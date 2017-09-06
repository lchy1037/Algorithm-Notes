# 面试题21：包含min函数的栈

## 题目描述

定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

## 求解策略

用一个辅助栈，每当把数据压入栈时，同时往辅助栈里压入该数据到栈底的最小元素。每当元素出栈时，辅助栈也相应的出栈。

## 实现代码

```c++
class Solution {
public:
    void push(int value) {
        dataStack.push(value);
        if (minStack.size() == 0 || value < minStack.top())
            minStack.push(value);
        else
            minStack.push(minStack.top());
    }
    void pop() {
        dataStack.pop();
        minStack.pop();
    }
    int top() {
        return dataStack.top();
    }
    int min() {
        return minStack.top();
    }
private:
    stack<int> dataStack;
    stack<int> minStack;
};
```