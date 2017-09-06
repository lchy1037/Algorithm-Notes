# 面试题41：和为S的两个数字VS和为S的连续正整数序列

## 题目1描述

输入一个递增排序的数组和一个数字`s`，在数组中查找两个数，使得它们的和正好是`s`。如果有多对数字的和等于`s`，输出任意一对即可。

## 求解策略

用两个指针`i,j`，`i`指向头，`j`指向尾。
1. 如果`ai+aj == sum`，则得到答案。
1. 如果`ai+aj > sum`，则`j`要向前移动；
1. 如果`ai+aj < sum`，则`i`要向后移动。

## 实现代码

```c++
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int len = array.size();
        vector<int> result;
        if (len < 2) return result;
        int front = 0, back = len-1;
        while (front < back){
            if (array[front]+array[back] == sum){
                result.push_back(array[front]);
                result.push_back(array[back]);
                break;
            } else if (array[front]+array[back] > sum) --back;
            else ++front;
        }
        return result;
    }
};
```

-------------------------------------------

## 题目2描述

输入一个正数`S`，打印出所有和为`S`的连续正数序列（至少含有两个数）。例如输入`15`，结果打印出 3 个连续序列：`1~5`，`4~6`，`7~8`。

## 求解策略

用两个数`front`和`back`两个数分别表示序列的最小值和最大值。
1. 先把`front`初始化为1，`back`初始化为2；
1. 如果从`front`到`back`的序列的和大于`S`，就增大`front`的值；
1. 如果从`front`到`back`的序列的和小于`S`，就增大`back`的值；
1. 因为序列中至少要有两个数字，一直增加到`front`到`(1+S)/2`为止。

## 实现代码

```c++
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        if (sum < 3) return result;
        int front = 1, back = 2;
        int mid = (1+sum)/2;
        int currSum = front + back;
        while (front < mid){
            if (currSum == sum){
                vector<int> sequence(back-front+1);
                for (int i = front; i <= back; ++i)
                    sequence[i-front] = i;
                result.push_back(sequence);
                currSum = currSum - (front++) + (++back);
            } else if (currSum > sum && front < mid){
                currSum -= front;
                ++front;
            } else {
                ++back;
                currSum += back;
            }
        }
        return result;
    }
};
```