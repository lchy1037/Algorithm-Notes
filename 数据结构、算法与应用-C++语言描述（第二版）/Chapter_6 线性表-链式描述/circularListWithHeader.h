#include "linearList.h"
#include "chain.h"
using namespace std;

template<typename T>
class circularListWithHeader : public linearList
{
public:
    circularListWithHeader();
    int indexOf(const T&) const;
protected:
    chainNode<T>* headerNode;
    int listSize;
};

// 定义
// 构造函数，新建空的单向循环链表
template<typename T>
circularListWithHeader<T>::circularListWithHeader(){
    headerNode = new chainNode<T>();
    headerNode->next = headerNode;
    listSize = 0;
}

// 返回元素首次出现时的索引
template<typename T>
int circularListWithHeader<T>::indexOf(const T& theElement) const{
    headerNode->element = theElement;

    chainNode<T>* currentNode = headerNode->next;
    int index = 0;
    // 比单向链表快，因为不需要对每一个迭代器检查条件是否为 NULL
    while (currentNode->element != theElement){
        currentNode = currentNode->next;
        index++;
    }
    if (currentNode == headerNode)
        return -1;
    else
        return index;
}