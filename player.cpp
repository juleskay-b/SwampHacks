//
// Created by Jules on 1/25/2025.
//

#include "player.h"
#include <iomanip>
#include <sstream>
using  namespace std;

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

int Time::getMinutes() {
    chrono::steady_clock::time_point thisTime = chrono::steady_clock::now();
    chrono::duration<int> time_span = chrono::duration_cast<chrono::duration<int>>(thisTime - start);
    int totalSeconds = time_span.count();
    int totalMinutes = (totalSeconds / 60) % 60 - 60*getHours();
    return totalMinutes;
}

int Time::getSeconds() {
    chrono::steady_clock::time_point thisTime = chrono::steady_clock::now();
    chrono::duration<int> time_span = chrono::duration_cast<chrono::duration<int>>(thisTime - start);
    int totalSeconds = time_span.count();
    totalSeconds = totalSeconds % 3600 - 60 * getMinutes();
    return totalSeconds;
}

int Time::getTotalSeconds() {
    auto now = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::seconds>(now - start).count();
}

int Time::getDate() {
    time_t now = chrono::system_clock::to_time_t(startDate);
    struct tm localTime = *localtime(&now);
    int formattedDate = (localTime.tm_year + 1900) * 10000 + (localTime.tm_mon + 1) * 100 + localTime.tm_mday;
    return formattedDate;
}

void player::printStats() {
    cout << "You have been playing for " << startTime.getHours() << " hours, " << startTime.getMinutes() << " minutes, and " << startTime.getSeconds() << " seconds!" << endl;
    cout << "Game started on: " << getDate() << endl;
    cout << "Total questions answered: " << questionsCorrect + questionsWrong << endl;
    cout << "Questions answered correctly: " << questionsCorrect << endl;
    cout << "Questions answered incorrectly: " << questionsWrong << endl;
    cout << "Total points earned: " << totalPointsEarned << endl;
}

string player::getDate() {
    int dateInt = startTime.getDate();
    int year = dateInt / 10000;
    int month = (dateInt / 100) % 100;
    int day = dateInt % 100;

    stringstream ss;
    ss << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day;
    return ss.str();
}

void player::answerQuestion(int points) {
    if (points > 0) {
        questionsCorrect++;
    } else {
        questionsWrong++;
    }
    totalPointsEarned += points;
    myPet.inc(points);
}

Pet& player::getPet() {
    return myPet;
}

Time player::getTime() {
    return startTime;
}
