//
// Created by 李喆昊 on 2021/9/23.
//

#include "Timer.h"
//#include <utility>

Timer::Timer(){
}

void Timer::start() {
    startTime = std::chrono::system_clock::now();
}

void Timer::end(const string &message) {
    auto endTime = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = endTime - startTime;
    printf("\033[1;36m[Timer] %s : %lf \033[0m\n", message.c_str(), elapsed_seconds.count());
}