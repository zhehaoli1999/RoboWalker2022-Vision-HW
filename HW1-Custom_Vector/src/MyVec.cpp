//
// Created by 李喆昊 on 2021/9/30.
//

#include "MyVec.h"

// 构造函数部分
MyVec::MyVec() : nSize(0), nCapacity(0), dataPtr(nullptr) {}

MyVec::MyVec(int n) : nSize(n), nCapacity(n + 10), dataPtr(nullptr) {
    dataPtr = new float[nCapacity]; // 分配新内存时永远都是分配nCapacity个
    for(int i = 0; i < nSize; i++)
        dataPtr[i] = 0.;
}

MyVec::MyVec(int n, const float t) : MyVec(n){
    for(int i = 0; i < n; i++)
        dataPtr[i] = t;
}

MyVec::MyVec(const MyVec &anotherMyVec): nSize(anotherMyVec.size()), nCapacity(anotherMyVec.capacity()) {
    dataPtr = new float[nCapacity];
    for (int i = 0; i < nSize; i++)
        dataPtr[i] = anotherMyVec.dataPtr[i];
}

// 插入数据部分
void MyVec::push_back(const float x) {
    if (dataPtr == nullptr)
        allocateMoreMem();
    if (nSize == nCapacity)
        allocateMoreMem();
    dataPtr[nSize++] = x;
}

int MyVec::insert(const int idx, const float x) {
    if (!dataPtr)
        allocateMoreMem();
    if (nSize == nCapacity)
        allocateMoreMem();
    for (int i = nSize++; i > idx; i--)
        dataPtr[i] = dataPtr[i - 1];
    dataPtr[idx] = x;
    return idx;
}


// 删除数据部分
int MyVec::erase(const int idx) {
    if (dataPtr == nullptr)
        throw "vector not initiate";
    if (idx >= nSize)
        throw "out of range";
    for (int i = idx; i < nSize - 1; i++)
        dataPtr[i] = dataPtr[i + 1];
    nSize--;
    return idx;
}

int MyVec::erase(const int first, const int last) {
    // first include, last exclude, so "last" is allowed to be equal to nSize
    if (dataPtr == nullptr)
        throw "vector not initiate";
    if (last > nSize || first >= nSize)
        throw "out of range";
    int len = last - first;
    for (int i = first; i < nSize - len; i++)
        dataPtr[i] = dataPtr[i + len];
    nSize = nSize - len;
    return len;
}

void MyVec::clear() {
    free(dataPtr);
    nSize = 0;
    nCapacity = 0;
    dataPtr = nullptr;
}

// 其他已实现的函数，可做参考
int MyVec::size() const {return this->nSize;}

bool MyVec::empty() const { return nSize == 0; }

float & MyVec::operator[](const int idx) {
    if(idx < nSize)
        return dataPtr[idx];
    else
        throw "Index out of range!";
}

float MyVec::operator[](const int idx) const {
    if(idx < nSize)
        return dataPtr[idx];
    else
        throw "Out of range!";
}

bool operator==(const MyVec& MyVec1, const MyVec& MyVec2) {
    if(MyVec1.dataPtr == MyVec2.dataPtr)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& out, const MyVec& mv)
{
    out << "[ ";
    for(int i = 0; i < mv.size(); i++)
    {
        out << mv[i] << " ";
    }
    out << "]";
    return out;
}

int MyVec::capacity() const { return nCapacity;}

bool MyVec::allocateMoreMem() {
    if(nCapacity == 0)
        nCapacity = 5; 
    nCapacity *= 2;
    float *newDataPtr = new float[nCapacity];
    if(newDataPtr == nullptr)
        throw "No more memory available!";
    else {
        memcpy(newDataPtr, dataPtr, nSize * sizeof(float));
        delete[] dataPtr;
        dataPtr = newDataPtr;
    }
}

void MyVec::operator=(const MyVec & anotherMyVec) {
    if(*this == anotherMyVec)
        return; // 防止自身拷贝

    nSize = anotherMyVec.size();
    nCapacity = anotherMyVec.capacity();

    if(dataPtr!= nullptr)
        delete[] dataPtr;

    if(nSize == 0) dataPtr = nullptr;
    else
    {
        dataPtr = new float[nCapacity]; // 分配新内存时永远都是分配nCapacity个
        for(int i = 0; i < nSize; i ++)
            dataPtr[i] = anotherMyVec[i];
    }
}

