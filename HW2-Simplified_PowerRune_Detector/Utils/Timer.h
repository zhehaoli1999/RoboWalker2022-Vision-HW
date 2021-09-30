//
// Created by 李喆昊 on 2021/9/23.
//

#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <string>
using namespace std::chrono;
using namespace std;

class Timer {
    Timer();
    void start();
    void end(const string& message);

private:
    time_point<system_clock> startTime;
};
#endif //TIMER_H
