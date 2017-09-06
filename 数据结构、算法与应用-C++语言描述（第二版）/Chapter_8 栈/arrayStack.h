#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

/* 通过线性表类的派生得到一个栈类时，付出的代价是性能的损失。所以这里单独开发一个栈类 */
/* 用数组 stack 来包含所有的栈元素，栈底元素是 stack[0]，栈顶元素是 stack[stackTop] */
#include "stack.h"

template<typename T>
void changeLength1D(T *&a, int oldLength, int newLength){
    if(newLength < 0){
        throw "new length must be > 0";
    }
    T *temp = new T[newLength];
    int number = min(oldLength, newLength);
    copy(a, a + number, temp);
    delete [] a;
    a = temp;
}

// 类声明
template<typename T>
class arrayStack
{
public:
    arrayStack(int initialCapacity = 10);
    ~arrayStack() {delete [] stack;}
    bool empty() const {return stackTop == -1;}
    int size() const {return stackTop + 1;}
    T& top() {
        if (stackTop == -1)
            throw "stack is empty!";
        return stack[stackTop];
    }
    void pop() {
        if (stackTop == -1)
            throw "stack is empty!";
        stack[stackTop--].~T();
    }
    void push(const T& theElement);

private:
    int stackTop;           // 当前栈顶
    int arrayLength;        // 栈容量
    T *stack;               // 元素数组
};

// 类定义
template<typename T>
arrayStack<T>::arrayStack(int initialCapacity){
    if (initialCapacity < 1){
        ostingstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw s.str();
    }
    arrayLength = initialCapacity;
    stack = new T[arrayLength];
    stackTop = arrayLength -1;
}

template<typename T>
void arrayStack<T>::push(const T& theElement){
    if (stackTop == arrayLength - 1){
        changeLength1D(stack, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }
    stack[++stackTop] = theElement;
}

#endif