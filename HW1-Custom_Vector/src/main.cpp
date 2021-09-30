//
// Created by 李喆昊 on 2021/9/30.
//
#include "MyVec.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    cout << "测试构造函数 MyVec()" << endl;
    MyVec v1;
    cout << v1 << endl; // should be "[ ]"

    cout << "测试构造函数 MyVec(int n)" << endl;
    MyVec v2(5);
    for(int i = 0; i< 5; i++)
        v2[i] = i+1;
    cout << v2 << endl;  // should be "[ 1 2 3 4 5 ]"

    cout << "测试拷贝构造函数 MyVec(const MyVec& anotherMyVec)" << endl;
    v2 = MyVec(v2);
    MyVec v3(v2);
    cout << v2 << endl; // should be "[ 1 2 3 4 5 ]"
    cout << v3 << endl; // should be "[ 1 2 3 4 5 ]"

    cout << "测试 void push_back(const float x) " << endl;
    for(int i = 6; i < 10; i++) {
        v2.push_back(float(i));
    }
    cout << v2 << endl;   // should be "[ 1 2 3 4 5 6 7 8 9]"
    for(int i = 1; i < 5; i++) {
        v1.push_back(float(i) - 0.5);
    }
    cout << v1 << endl;   // should be "[ 0.5 1.5 2.5 3.5 ]"

    cout << "测试 int insert(const int idx, const float x) " << endl;
    v2.insert(v2.insert(4, 4.5), 4.25);
    cout << v2 << endl;   // should be "[ 1 2 3 4 4.25 4.5 5 6 7 8 9]"
    MyVec v4;
    v4.insert(0, 0.4);
    v4.insert(0, 0.8);
    cout << v4 << endl; // should be "[ 0.8 0.4 ]"

    cout << "测试 int erase(const int idx) " << endl;
    v2.erase(v2.erase(6));
    cout << v2 << endl; // shoule be "[ 1 2 3 4 4.25 4.5 7 8 9]"

    cout << "测试 int erase(const int first, const int last)  " << endl;
    v2.erase(2, 5);
    cout << v2 << endl; // shoule be "[ 1 2 4.5 7 8 9]"

    cout << "测试 clear() " << endl;
    v2.clear();
    cout << v2 << endl; // should be "[ ]"

    // 附加的随机测试（可能存在异常参数 & 错误情况）
    // 
    // 在提交作业后测试，统计正确率
    return 0;
}