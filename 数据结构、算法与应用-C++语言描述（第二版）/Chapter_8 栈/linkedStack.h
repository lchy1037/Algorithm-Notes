#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

/* 若用链表的右端作为栈顶，则每一个链表方法都需要用时 O(size())；而用链表左边作为栈顶，需要用时 O(1)。*/
/* 分析表明，应该选择链表左端作为栈顶 */

#include "../Chapter_6 线性表-链式描述/chain.h"
#include "stack.h"

// linkedStack 类的定义
template<typename T>
class linkedStack : public stack<T>
{
public:
    linkedStack (int initialCapacity = 10) {stackTop = NULL; stackSize = 0;}
    ~linkedStack();

    bool empty() const {return stackSize == 0;}

    int size() const {return stackSize;}

    T& top() {
        if (stackSize == 0)
            throw "stack is empty!";
        return stackTop->element;
    }

    void pop();
    
    void push(const T& theElement){
        stackTop = new chainNode<T>(theElement, stackTop);
        stackSize++;
    }

private:
    chainNode<T> *stackTop;     // 栈顶指针
    int stackSize;              // 栈中元素个数
};

template<typename T>
linkedStack<T>::~linkedStack(){
    while (stackTop != NULL){
        chainNode<T> *nextNode = stackTop->next;
        delete stackTop;
        stackTop = nextNode;
    }
}

template<typename T>
void linkedStack<T>::pop(){
    if (stackSize == 0)
        throw "stack is empty!";
    
    chainNode<T> *nextNode = stackTop->next;
    delete stackTop;
    stackTop = nextNode;
    stackSize--;
}

#endif