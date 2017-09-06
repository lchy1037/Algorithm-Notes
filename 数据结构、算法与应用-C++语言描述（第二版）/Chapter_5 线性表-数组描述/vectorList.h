#ifndef VECTOR_LIST_H
#define VECTOR_LIST_H

#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "linearList.h"
using namespace std;

// 用 vector 描述线性表
template<typename T>
class vectorList : public linearList<T>
{
public:
    // 构造函数，复制构造函数和析构函数
    vectorList(int initialCapacity = 10);
    vectorList(const vectorList<T>&);
    ~vectorList() {delete element;}

    // ADT 方法
    bool empty() const {return element->empty();}
    int size() const {return element->size();}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

protected:
    void checkIndex(int theIndex) const;
    vector<T> *element;
};

// ----------------------------------------- 定义
template<typename T>
vectorList<T>::vectorList(int initialCapacity)
{   // 构造函数
    if(initialCapacity < 1){
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0.";
        throw s.str();
    }
    element = new vector<T>;        // 创建容量为 0 的空向量
    element->reserve(initialCapacity);      // 容量从 0 增加到 initialCapacity
}

template<typename T>
vectorList<T>::vectorList(const vectorList<T>& theList)
{
    element = new vector<T>(*theList.element);
}

template<typename T>
void vectorList<T>::checkIndex(int theIndex) const
{
    if(theIndex < 0 || theIndex > element->size() - 1){
        ostringstream s;
        s << "index = " << theIndex << " size = " << element->size();
        throw s.str();
    }
}

template<typename T>
T& vectorList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element->at(theIndex);
}

template<typename T>
int vectorList<T>::indexOf(const T& theElement) const
{
    // int theIndex = (int)(find(*element, *element->size(), theElement) - element);
    // if(theIndex == element->size()){
    //     return -1;
    // }else{
    //     return theIndex;
    // }
}

template<typename T>
void vectorList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    element->erase(element->begin() + theIndex);
}

template<typename T>
void vectorList<T>::insert(int theIndex, const T& theElement)
{
    if(theIndex < 0 || theIndex > size()){
        ostringstream s;
        s << "index = " << theIndex << " size = " << size();
        throw s.str();
    }
    element->insert(element->begin() + theIndex, theElement);
}

template<typename T>
void vectorList<T>::output(ostream& out) const
{
    // copy(element, element + element->size(), ostream_iterator<T>(out, " "));
}

#endif // !VECTOR_LIST_H