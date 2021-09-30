//
// Created by 李喆昊 on 2021/9/30.
//

#ifndef MYVEC_H
#define MYVEC_H

#include <exception>
#include <iostream>
#include <cstring>

using namespace std;

class MyVec {
public:
    MyVec();
    MyVec(int n); // 其实MyVec() 可以认为是MyVec(int n=0)，可以使用默认参数实现
    MyVec(int n, const float t);
    MyVec(const MyVec& anotherMyVec);

    void push_back(const float x);
    int insert(const int idx, const float x);

    int erase(const int idx);
    int erase(const int first, const int last);
    void clear();

    /*
     * 其他一些已经实现的函数供参考
     */
    bool empty() const; // 返回向量是否为空
    int size() const; // 返回向量的size
    int capacity() const; // 返回向量的capacity，用于预先内存分配

    float& operator[](const int idx); // 返回向量中下标为idx的元素的引用
    float operator[](const int idx) const; // 返回向量中下标为idx的元素的值，不会修改向量中的元素

    void operator=(const MyVec& anotherMyVec); // 赋值函数，进行拷贝
    friend bool operator==(const MyVec& MyVec1, const MyVec& MyVec2); // 比较两个向量是否相同
    friend ostream& operator<<(ostream&, const MyVec&);  // 用于cout输出

private:
    bool allocateMoreMem(); // 成倍分配新内存

    int nSize;
    int nCapacity;
    float* dataPtr;
};


#endif //MYVEC_H
