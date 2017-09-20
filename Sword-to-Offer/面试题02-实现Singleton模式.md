# 面试题2：实现Singleton模式

## 题目描述

设计一个类，只能生成该类的一个实例。

## 求解策略

饿汉模式：

```c++
#include <iostream>
#include <mutex>
using namespace std;

/* singleton model */
/* 双重校验 */
class Singleton{
public:
    static Singleton* GetInstance(){
        if (instance == nullptr){
            locker->lock();
            if (instance == nullptr){
                instance = new Singleton();
            }
            locker->unlock();
        }
        return instance;
    }
private:
    Singleton(){}
    static Singleton* instance;
    static mutex* locker;
};

Singleton* Singleton::instance = nullptr;
mutex* Singleton::locker = new mutex();

/* Singleton model 2 */
/* 饿汉式单例 */
class Singleton2{
public:
    static Singleton2* GetInstance(){
        return instance;
    }
private:
    Singleton2(){}
    static Singleton2* instance;
};

Singleton2* Singleton2::instance = new Singleton2();

int main(int argc, char** argv){
    Singleton* inst1 = Singleton::GetInstance();
    Singleton* inst2 = Singleton::GetInstance();
    cout << inst1 << endl;
    cout << inst2 << endl;

    Singleton2* inst21 = Singleton2::GetInstance();
    Singleton2* inst22 = Singleton2::GetInstance();
    cout << inst21 << endl;
    cout << inst22 << endl;
    return 1;
}
```

代码输出：
```c++
0x671988
0x671988
0x671958
0x671958
```

## 本题考点

- 考察对单例（Singleton）模式的理解
- 考察对多线程编程的理解。