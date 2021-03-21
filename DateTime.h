//
// Created by seraf on 16.03.2021.
//

#ifndef PROIECTOOP_DATETIME_H
#define PROIECTOOP_DATETIME_H
#include <ctime>
#include <iostream>


class DateTime {
    int hour, min;
    int day, mon, yr;
public:
    DateTime();
    DateTime(int hour, int min, int day, int mon, int yr);
    DateTime(DateTime &A);
    ~DateTime();
    DateTime& operator=(const DateTime& A);
    int operator>(const DateTime &A);
    friend std::ostream &operator<<(std::ostream &out, const DateTime &A);
    friend std::istream &operator>>(std::istream &in, DateTime &A);
    void printHour() const;
    void printDate() const;
    int getMinute();
    int getHour();
    int getDay();
    int getMon();
    int getYear();
    void addDay();
    void addMinutes(int minutes);
};

#endif //PROIECTOOP_DATETIME_H
