#ifndef DERIVEDARRAYSTACK_H
#define DERIVEDARRAYSTACK_H

/* 该类是从类 arrayList 和 stack 派生的类 derivedArrayStack */

#include "../Chapter_5 线性表-数组描述/arrayList.h"
#include "stack.h"

template<typename T>
class derivedArrayStack : private arrayList<T>, public stack<T>
{
public:
    derivedArrayStack(int initialCapacity = 10) : arrayList<T>(initialCapacity) {}

    bool empty() const {return arrayList<T>::empty();}

    int size() const {return arrayList<T>::size();}

    T& top() {
        if (arrayList<T>::empty())
            throw "stack is empty!";
        return get(arrayList<T>::size() - 1);
    }

    void pop() {
        if (arrayList<T>::empty())
            throw "stack is empty!";
        erase(arrayList<T>::size() - 1);
    }

    void push(const T& theElement) {
        insert(arrayList<T>::size(), theElement);
    }
};

#endif