//
// Created by Jules on 1/25/2025.
//

#include "player.h"
#include <iomanip>
#include <sstream>

struct tm datetime;
time_t timestamp;

Time::Time() {
    start = chrono::steady_clock::now();
    startDate = chrono::system_clock::now();
    time_t now = chrono::system_clock::to_time_t(startDate);
    datetime = *localtime(&now);
}

int Time::getHours() {
    chrono::steady_clock::time_point thisTime = chrono::steady_clock::now();
    chrono::duration<int> time_span = chrono::duration_cast<chrono::duration<int>>(thisTime - start);
    int totalSeconds = time_span.count();
    int totalHours = totalSeconds / 3600;
    return totalHours;
}

int Time::getDate() {
    time_t now = chrono::system_clock::to_time_t(startDate);
    struct tm localTime = *localtime(&now);
    int formattedDate = (localTime.tm_year + 1900) * 10000 + (localTime.tm_mon + 1) * 100 + localTime.tm_mday;
    return formattedDate;
}

player::player() {
    startTime = Time();
}

void player::printTimePlayed() {
    cout << "You have been playing for " << startTime.getHours() << " hours!" << endl;
    cout << "Game started on: " << getDate() << endl;
}

string player::getDate() {
    int dateInt = startTime.getDate();
    int year = dateInt / 10000;
    int month = (dateInt / 100) % 100;
    int day = dateInt % 100;

    stringstream ss;
    ss << year << "-" << setw(2) << setfill('0') << month << "-"
       << setw(2) << setfill('0') << day;
    return ss.str();
}