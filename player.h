//
// Created by Jules on 1/25/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <chrono>
#include <iostream>
#include <ctime>
using namespace std;

struct Time {
    chrono::steady_clock::time_point start;
    chrono::system_clock::time_point startDate;
    struct tm datetime;
public:
    Time();
    int getHours();
    int getDate();
};

class player {
    Time startTime;
public:
    player();
    void printTimePlayed();
    string getDate();
};



#endif //PLAYER_H
