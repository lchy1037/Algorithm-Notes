#ifndef QUEUE_H
#define QUEUE_H
/* 抽象队列 */

template<typename T>
class queue
{
public:
    virtual ~queue() {}

    virtual bool empty() const = 0;                 // 返回 true，当且仅当队列为空

    virtual int size() const = 0;                   // 返回队列中元素个数

    virtual T& front() = 0;                         // 返回队列首元素

    virtual T& back() = 0;                          // 返回队列尾元素

    virtual void pop() = 0;                         // 删除首元素

    virtual void push(const T& theElement) = 0;     // 把元素 theElement 加入队尾
};

#endif