# 队列

队列是一种特殊的线性表，其插入和删除操作分别在线性表的两端进行，因此，队列是一个先进先出（FIFO）的线性表。C++标准模板库STL的队列是一种用数组描述的队列数据结构，它是从STL的双端队列派生的。

## 定义

队列（queue）是一个线性表，其插入和删除操作分别在表的不同端进行。插入元素的那一端称为队尾（back或rear），删除元素的那一端称为队首（front）。

## 抽象数据类型

```
抽象数据类型 queue
{
    实例：
        元素的有序表，一端称为队首，另一端称为队尾

    操作：
        empty();        // 返回 true，当且仅当队列为空，否则返回 false
        size();         // 返回队列中元素个数
        front();        // 返回队列头元素
        back();         // 返回队列尾元素
        pop();          // 删除队列首元素
        push(x);        // 把元素 x 加入队尾
}
```