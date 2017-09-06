# 面试题2：实现Singleton模式

## 题目描述

设计一个类，只能生成该类的一个实例。

## 求解策略

饿汉模式：

```c++
class Singleton{
public:
    static Singleton* GetInstance(){
        return instance;
    }
private:
    Singleton(){};
    static Singleton* instance;
};

Singleton* Singleton::instance = new Singleton();
```

## 本题考点

- 考察对单例（Singleton）模式的理解
- 考察对多线程编程的理解。