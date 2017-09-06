#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <sstream>
#include <algorithm>
#include <iterator>
#include "linearList.h"

using namespace std;

// 用数组描述线性表
template<typename T>
class arrayList : public linearList<T>
{
public:
    // 构造函数，复制构造函数和析构函数
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T>&);
    ~arrayList() {delete [] element;};

    // ADT 方法
    bool empty() const {return listSize == 0;}
    int size() const {return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;
    int capacity() const {return arrayLength;}

protected:
  void checkIndex(int theIndex) const;                // 若索引 theIndex 无效，则抛出异常
  T *element;      // 存储线性表元素的一维数组
  int arrayLength; // 一维数组的容量
  int listSize;    // 线性表的元素个数
};

//-----------------------------------------------定义
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

template<typename T>
arrayList<T>::arrayList(int initalCapacity)
{   // 构造函数
    if(initalCapacity < 1){
        ostringstream s;
        s << "Initial capacity = " << initalCapacity << " Must be > 0";
        throw s.str();
    }
    arrayLength = initalCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template<typename T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{   // 复制构造函数
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element + listSize, element);
}

template<typename T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if(theIndex < 0 || theIndex > listSize - 1){
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw s.str();
    }
}

template<typename T>
T& arrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element[theIndex];
}

template<typename T>
int arrayList<T>::indexOf(const T& theElement) const
{
    int theIndex = (int)(find(element, element + listSize, theElement) - element);
    if(theIndex == listSize){
        return -1;
    }else{
        return theIndex;
    }
}

template<typename T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    copy(element + theIndex + 1, element + listSize, element + theIndex);
    element[--listSize].~T();
}

template<typename T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
    if(theIndex < 0 || theIndex > listSize){
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw s.str();
    }

    if(listSize == arrayLength){
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    copy_backward(element + theIndex, element + listSize, element + listSize + 1);
    element[theIndex] = theElement;
    listSize++;
}

template<typename T>
void arrayList<T>::output(ostream &out) const
{
    copy(element, element + listSize, ostream_iterator<T>(out, " "));
}

template<typename T>
ostream& operator<<(ostream &out, const arrayList<T>& x)
{
    x.output(out);
    return out;
}

#endif