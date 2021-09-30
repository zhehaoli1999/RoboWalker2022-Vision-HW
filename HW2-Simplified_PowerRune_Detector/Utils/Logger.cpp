//
// Created by 李喆昊 on 2021/9/23.
//

#include "Logger.h"

Logger::Logger() {}

/*
 * Ref: https://stackoverflow.com/a/10467633/11825645
 */
const string Logger::getNowTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
}

/*
 * Ref: https://stackoverflow.com/a/2616912/11825645
 */
ostream& Logger::error(){
    return cout << "\033[1;31m[" << getNowTime() << "] [Error]" << "\033[0m" ;
}

ostream& Logger::warning() {
    return cout << "\033[1;33m[" << getNowTime() << "] [Warning]" "\033[0m";
}

ostream& Logger::debug() {
    return cout << "\033[1;32m[" << getNowTime() << "] [Debug]" << "\033[0m";
}