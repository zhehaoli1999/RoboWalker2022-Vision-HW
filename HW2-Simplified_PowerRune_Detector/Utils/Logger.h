//
// Created by 李喆昊 on 2021/9/23.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <ctime>
#include <iostream>

using namespace std;

class Logger {
public:
    Logger();
    static ostream& error();
    static ostream& warning();
    static ostream& debug();
    static const string getNowTime();
private:

};


#endif //LOGGER_H
