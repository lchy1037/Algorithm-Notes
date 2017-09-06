#ifndef LINEAE_LIST_H
#define LINEAE_LIST_H

#include <iostream>
using namespace std;

// 声明一个抽象数据类型，不能实例化
template<typename T>
class linearList
{
public:
    virtual ~linearList(){};

    virtual bool empty() const = 0;         // 返回true，当且仅当线性表为空

    virtual int size() const = 0;           // 返回线性表的元素个数

    virtual T& get(int theIndex) const = 0;         // 返回索引为 theIndex 的元素

    virtual int indexOf(const T& theElement) const = 0;         // 返回元素 theElement 第一次出现的索引

    virtual void erase(int theIndex) = 0;                 // 删除索引为 theIndex 的元素

    virtual void insert(int theIndex, const T& theElement) = 0;           // 把 theElement 插入线性表中索引为 theElement 的位置上

    virtual void output(ostream &out) const = 0;                // 把线性表插入输出流 out
};

#endif