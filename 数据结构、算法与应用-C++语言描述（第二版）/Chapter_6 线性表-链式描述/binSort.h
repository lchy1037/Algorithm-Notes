#ifndef BIN_SORT_H
#define BIN_SORT_H

// 箱子排序：首先把分数相同的节点放在同一个箱子里，然后把箱子链接起来就得到有序的链表

#include <iostream>
#include <string>
#include "chain.h"
using namespace std;

struct studentRecord{
    int score;
    string *name;

    int operator!=(const studentRecord& x) const {return (score != x.score);}
    operator int() const {return score;}
};

ostream& operator<<(ostream& out, const studentrecord& x){
    out << x.score << " " << *x.name << endl;
    return out;
}

void binSort(chain<studentRecord>& theChain, int range){    // 按分数排序
    // 对箱子初始化
    chain<studentRecord> *bin;
    bin = new chain<studentRecord>[range+1];

    // 把学生记录从链表中取出，然后分配到箱子里
    int numberOfElements = theChain.size();
    for (int i = 0; i < numberOfElements; ++i){
        studentRecord x = theChain.get(0);
        theChain.erase(0);
        bin[x.score].insert(0, x);
    }

    // 从箱子中收集元素
    for (int j = range; j >= 0; --j){
        while (!bin[j].empty()){
            studentRecord x = bin[j].get(0);
            bin[j].erase(0);
            theChain.insert(0, x);
        }
    }
    delete [] bin;
}

#endif