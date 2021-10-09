//
// Created by 李喆昊 on 2021/9/30.
//

#ifndef MYVEC_H
#define MYVEC_H

#include <exception>
#include <iostream>
#include <cstring>

using namespace std;

// 类的封装：数据 + 函数
class MyVec {
public:
    MyVec();
    MyVec(int n); // 其实MyVec() 可以认为是MyVec(int n=0)，可以使用默认参数实现
    
    // 需要实现的函数
    // 创建一个长度为n的向量，每个元素为t（构造函数）
    MyVec(int n, const float t); 
    // 拷贝构造函数
    MyVec(const MyVec& anotherMyVec); 
    
    // 向末尾增加一个元素x
    void push_back(const float x); 

    //在下标为idx的元素前增加元素x，返回x的下标（由于元素的移动，x下标其实就是idx)
    int insert(const int idx, const float x); 

    // 删除下标为idx的函数（注意错误处理）返回后一个元素的下标（其实后一个元素会被移动到前面，下标仍然是idx)，如果后一个元素不在向量里，返回-1
    int erase(const int idx); 

    // 删除向量中[first,last)中元素，返回后一个元素的下标，如果后一个元素不在向量里，返回-1
    int erase(const int first, const int last); 

    // 清空向量中所有元素
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
    void allocateMoreMem(); // 成倍分配新内存

    int nSize;
    int nCapacity;
    float* dataPtr;
};

#endif //MYVEC_H
