#ifndef CHAIN_H
#define CHAIN_H

#include <sstream>
#include <algorithm>
#include <iterator>
#include "linearList.h"
using namespace std;

// 链表节点的结构定义
template<typename T>
struct chainNode
{
    // 数据成员
    T element;
    chainNode<T> *next;

    // 方法
    chainNode() {}
    chainNode(const T& element){
        this->element = element;
        this->next = NULL;
    }
    chainNode(const T& element, chainNode<T>* next){
        this->element = element;
        this->next = next;
    }
};

// 链表声明
template<typename T>
class chain : public linearList
{
public:
    // 构造函数，复制构造函数和析构函数
    chain(int initialCapacity = 10);
    chain(const chain<T>&);
    ~chain();

    // 抽象数据类型 ADT 方法
    void clear();
    bool empty() const {return listSize == 0;}
    int size() const {return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(osream& out) const;

    void binSort(int range);
protected:
    void checkIndex(int theIndex) const;
    chainNode<T>* firstNode;
    int listSize;
};

// 链表定义
// 构造函数
template<typename T>
chain<T>::chain(int initialCapacity){
    if (initialCapacity < 1){
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0.";
        throw s.str();
    }
    firstNode = NULL;
    listSize = 0;
}

// 复制构造函数
template<typename T>
chain<T>::chain(const chain<T>& theList){
    listSize = theList.listSize;
    if (listSize == 0){
        firstNode = NULL;
        return;
    }
    chainNode<T>* sourceNode = theList.firstNode;
    fistNode = new chainNode<T>(sourceNode->element);
    sourceNode = sourceNode->next;
    chainNode<T>* targetNode = firstNode;
    while (sourceNode != NULL){
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL;
}

// 析构函数
template<typename T>
chain<T>::~chain(){
    while(firstNode != NULL){
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

// 判断索引有效性
template<typename T>
chain<T>::checkIndex(int theIndex){
    if (theIndex < 0 || theIndex > listSize - 1){
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw s.str();
    }
}

// 删除链表的所有节点
template<typename T>
void chain<T>::clear(){
    while (firstNode != NULL){
        chainNode<T>* currentNode = firstNode->next;
        delete firstNode;
        firstNode = currentNode;
    }
    listSize = 0;
}

// 返回索引为 theIndex 的元素
template<typename T>
T& chain<T>::get(int theIndex) const{
    checkIndex(theIndex);
    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex; ++i){
        currentNode = currentNode->next;
    }
    return currentNode->element;
}

// 返回元素首次出现时的索引
template<typename T>
int chain<T>::indexOf(const T& theElement) const{
    chainNode<T>* currentNode = firstNode;
    int index = 0;
    while (currentNode != NULL && currentNode->element != theElement){
        currentNode = currentNode->next;
        ++index;
    }
    if(currentNode == NULL)
        return -1;
    else
        return index;
}

// 删除索引为 theIndex 的元素
template<typename T>
void chain<T>::erase(int theIndex){
    checkIndex(theIndex);
    chainNode<T>* deleteNode;
    if (theIndex == 0){
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }else{
        chainNode<T>* p = firstNode;
        for(int i = 0; i < theIndex-1; ++i){
            p = p->next;
        }
        deleteNode = p->next;
        p->next = p->next->next;
    }
    --listSize;
    delete deleteNode;
}

// 插入元素 theElement 并使其索引为 theIndex
template<typename T>
void chain<T>::insert(int theIndex, const T& theElement){
    if (theIndex < 0 || theIndex > listSize){
        ostringstream s;
        s << "Invalid index.";
        throw s.str();
    }
    if(theIndex == 0){
        firstNode = new chainNode<T>(theElement, firstNode);
    }else{
        chainNode<T>* p = firstNode;
        for(int i = 0; i < theIndex - 1; ++i){
            p = p->next;
        }
        p->next = new chainNode<T>(theElement, p->next);
    }
    ++listSize;
}

// 箱子排序
template<typename T>
void chain<T>::binSort(int range){
    // 创建并初始化箱子
    chainNode<T> **bottom, **top;
    bottom = new chainNode<T>*[range+1];
    top = new chainNode<T>*[range+1]；
    for(int b = 0; b <= range; ++b){
        bottom[b] = NULL;
    }

    // 把链表的节点分配到箱子
    for (; firstNode != NULL; firstNode = firstNode->next){
        int theBin = firstNode->element;
        if (bottom[theBin] == NULL)
            bottom[theBin] = top[theBin] = firstNode;
        else{
            top[theBin]->next = firstNode;
            top[theBin] = firstNode;
        }
    }

    // 把箱子中的节点收集到有序链表
    chainNode<T> *y = NULL;
    for (int theBin = 0; theBin <= range; ++theBin){
        if (bottom[theBin] != NULL){
            if (y == NULL)
                firstNode = bottom[theBin];
            else
                y->next = bottom[theBin];
            y = top[theBin];
        }
    }
    if (y != NULL) y->next = NULL;
    delete [] bottom;
    delete [] top;
}

// 输出链表
template<typename T>
void chain<T>::output(ostream& out) const{
    for (chainNode<T>* currentNode = firstNode; 
    currentNode != NULL; 
    currentNode = currentNode->next){
        out << currentNode->element << " ";
    }
}

template<typename T>
ostream& operator<<(ostream& out, const chain<T>& x){
    x.output(out);
    return out;
}

#endif