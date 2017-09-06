#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "maxPriorityQueue.h"
#include <sstream>
#include <algorithm>

using namespace std;

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
class maxHeap : public maxPriorityQueue<T>
{
    public:
        maxHeap(int initialCapacity = 10);
        ~maxHeap() {delete [] heap;}
        bool empty() const {return heapSize == 0;}
        int size() const {return heapSize;}
        const T& top(){
            if (heapSize == 0)
                throw "error! Heap size = 0.";
            return heap[1];
        }
        void pop();
        void push(const T&);
        void initialize(T*, int);
        void deactivateArray(){
            heap = NULL;
            arrayLength = heapSize = 0;
        }
        void output(ostream& out) const;
    private:
        int heapSize;       // number of elements in queue
        int arrayLength;    // queue capacity + 1
        T *heap;            // element array
};

// 类定义
template<typename T>
maxHeap<T>::maxHeap(int initialCapacity){
    if (initialCapacity < 1){
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0.";
        throw s.c_str();
    }
    arrayLength = initialCapacity + 1;
    heap = new T[arrayLength];
    heapSize = 0;
}

template<typename T>
void maxHeap<T>::push(const T& theElement){
    // 必要时增加数组长度
    if (heapSize == arrayLength - 1){
        changeLength1D(heap, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }
    
    // 为元素 theElement 寻找插入位置，cyrrentNode 从新叶子向上移动
    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] < theElement){
        heap[currentNode] = heap[currentNode / 2];
        currentNode /= 2;
    }
    heap[currentNode] = theElement;
}

template<typename T>
void maxHeap<T>::pop(){
    if (heapSize == 0)
        throw "error! heap is empty.";

    // 删除最大的元素
    heap[1].~T();
    
    // 删除最后一个元素，然后重新建堆
    T lastElement = heap[heapSize--];
    int currentNode = 1, child = 2;
    while (child <= heapSize){
        if (child < heapSize && heap[child] < heap[child + 1])
            child++;
        if(lastElemetn >= heap[child])
            break;
        heap[currentNode] = heap[child];
        currentNode = child;
        child *= 2;
    }
    heap[currentNode] = lastElement;
}

template<typename T>
void maxHeap<T>::initialize(T *theHeap, int theSize)
{// Initialize max heap to element array theHeap[1:theSize].
    delete [] heap;
    heap = theHeap;
    heapSize = theSize;

    // 堆化
    for (int root = heapSize / 2; root >= 1; --root){
        T rootElement = heap[root];
        int child = 2*root;
        while (child <= heapSize){
            if (child < heapSize && heap[child] < heap[child + 1])
                ++child;
            if (rootElement >= heap[child])
                break;
            heap[child/2] = heap[child];
            child *= 2;
        }
        heap[child/2] = rootElement;
    }
}

template<typename T>
void maxHeap<T>::output(ostream& out) const
{// Put the list into the stream out.
   copy(heap + 1, heap + heapSize + 1, ostream_iterator<T>(cout, "  "));
}

// overload <<
template<typename T>
ostream& operator<<(ostream& out, const maxHeap<T>& x)
   {x.output(out); return out;}

#endif