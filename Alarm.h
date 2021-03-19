//
// Created by seraf on 18.03.2021.
//

#ifndef PROIECTOOP_ALARM_H
#define PROIECTOOP_ALARM_H


#include <string>
#include "DateTime.h"

class Alarm {
    DateTime time;
    std::string message;
    bool recurrent;
public:
    Alarm(int hour, int min,  std::string msg, bool recurrent);
    Alarm(DateTime time, std::string msg, bool recurrent);
    Alarm(const Alarm& A);
    /*Alarm& recurringAlarm();*/
    bool isRecurrent();
    void setMessage(std::string message);
    void setRecurrence(bool recurrence);
    friend std::ostream &operator<<(std::ostream& out, Alarm &A);
    DateTime getTime();
    /// implement function to "ring" alarm?
};


#endif //PROIECTOOP_ALARM_H
