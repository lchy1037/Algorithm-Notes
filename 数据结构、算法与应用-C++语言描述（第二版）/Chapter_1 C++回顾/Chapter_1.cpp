#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 计算一个整形表达式 */
template<typename T>
T abc(T &a, T &b, T &c){
    if(a <= 0 || b <= 0 || c <= 0){
        throw "All parameters should be > 0.";      // 抛出异常
    }
    return a+b*c;
}

int main(int argc, char **argv)
{
    /*-------------------- 处理异常 ---------------------*/
    try {cout << abc(-1, 0, 1) << endl;}
    catch(const char *e){
        cout << "An exception has been thrown." << endl;
        cout << e << endl;
        return 1;
    }

    /*-------------------- 动态存储空间分配 ----------------------*/
    int *new_int_x = new int(10);       // 为一个值为10的整形变量分配存储空间
    float *new_float_x = new float[10];     // 为10个浮点数分配存储空间
    float *exception_new_x;
    try {exception_new_x = new float[100];}
    catch(bad_alloc e){     // 仅当new 失败是进入
        cout << "Out of Memory" << endl;
        exit(1);
    }

    /*----------------- 动态分配二维数组 ----------------------*/
    int **x;
    int rows = 3, cols = 4;
    x = new int*[rows]          // 分配
    for(int i = 0; i < rows; ++i){
        x[i] = new int[cols];
    }

    for(int i = 0; i < rows; ++i){        // 释放
        delete [] x[i];
    }
    delete [] x;

    /*----------------- 动态分配三维数组 ----------------------*/
    int ***x;
    int width = 3, height = 4, channels = 2;
    x = new int**[channels];       // 动态分配空间
    for(int i = 0; i < channels; ++i){
        x[i] = new int*[width];
        for(int j = 0; j < width; ++j){
            x[i][j] = new int[height];
            for(int k = 0; k < height; ++k){
                x[i][j][k] = i*j*k;
            }
        }
    }

    for (int i = 0; i < channels; ++i){        // 赋值
        for (int j = 0; j < width; ++j){
            for (int k = 0; k < height; ++k)
                cout << x[i][j][k] << "\t";
            cout << endl;
        }
        cout << endl;
    }

    for(int i = 0; i < channels; ++i){     // 释放
        for(int j = 0; j < width; ++j){
            delete []x[i][j];
        }
        delete [] x[i];
    }
    delete [] x;

    return 0;
}