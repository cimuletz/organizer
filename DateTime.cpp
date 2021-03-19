//
// Created by seraf on 16.03.2021.
//
#include <iostream>
#include <ostream>
#include "DateTime.h"

    DateTime::DateTime(){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        this -> yr = 1900 + ltm->tm_year;
        this -> mon = 1 + ltm->tm_mon;
        this -> day = ltm->tm_mday;
        this -> hour = 5+ltm->tm_hour;
        this -> min = 30+ltm->tm_min;
    }

    DateTime::DateTime(int hour, int min, int day, int mon, int yr) : hour(hour), min(min), day(day), mon(mon), yr(yr) {}

    DateTime::DateTime(DateTime &A) {
    this -> hour = A.hour;
    this -> min = A.min;
    this -> day = A.day;
    this -> mon = A.mon;
    this -> yr = A.yr;
    }

    DateTime::~DateTime() {}

    DateTime &DateTime::operator=(const DateTime &A) {
        if (&A != this) {
            this -> hour = A.hour;
            this -> min = A.min;
            this -> day = A.day;
            this -> mon = A.mon;
            this -> yr = A.yr;
        }
        return *this;
    }

    int DateTime::operator>(const DateTime &A){
        if( this -> yr > A.yr )
            return 1;
        if( this -> mon > A.mon )
            return 1;
        if( this -> day > A.day )
            return 1;
        if( this -> hour > A.hour )
            return 1;
        if( this -> min > A.min )
            return 1;
        return 0;
    }

    std::ostream &operator<<(std::ostream &os, const DateTime &data) {
        os << data.day <<"-" << data.mon << "-" << data.yr << " " << data.hour<<":"<<data.min<<"\n";
        return os;
    }

    std::istream &operator>>(std::istream &in, DateTime &A) {
        in >> A.day >> A.mon >> A.yr >> A.hour >> A.min;
        return in;
    }

    void DateTime::printHour() const {
        std::cout << this -> hour << ":" << this -> min;
    }

    int DateTime::getMinute(){
        return this -> min;
    }
    int DateTime::getHour(){
        return this -> hour;
    }
    int DateTime::getDay(){
        return this -> day;
    }
    int DateTime::getMon(){
        return this -> mon;
    }
    int DateTime::getYear(){
        return this -> yr;
    }

    void DateTime::addDay(){
        this -> day++;
        if (this -> mon == 1 || this -> mon == 3 || this -> mon == 5 || this -> mon == 7 || this -> mon == 8 || this -> mon == 10 ||
            this -> mon == 12 ) {
            if (this -> day > 31) {
                this -> mon++;
                this -> day -= 30;
            }
        } else if (this -> mon == 4 || this -> mon == 6 || this -> mon == 9 || this -> mon == 11) {
            if (this -> day > 30) {
                this -> mon++;
                this -> day -= 29;
            }
        } else if ((this -> yr % 4 == 0 && this -> yr % 100 != 0) || this -> yr % 400 == 0) {
            if (this -> day > 29) {
                this -> mon++;
                this -> day -= 28;
            } else {
                this -> mon++;
                this -> day -= 27;
            }
        }
        if(this -> mon > 12) {
            this->mon = 1;
            this->yr++;
        }
    }

    void DateTime::addMinutes(int minutes) {
        this -> min += minutes;
        this -> hour += this -> min / 60;
        if (this -> mon == 1 || this -> mon == 3 || this -> mon == 5 || this -> mon == 7 || this -> mon == 8 || this -> mon == 10 ||
            this -> mon == 12 ) {
            if (this -> day > 31) {
                this -> mon++;
                this -> day -= 30;
            }
        } else if (this -> mon == 4 || this -> mon == 6 || this -> mon == 9 || this -> mon == 11) {
            if (this -> day > 30) {
                this -> mon++;
                this -> day -= 29;
            }
        } else if ((this -> yr % 4 == 0 && this -> yr % 100 != 0) || this -> yr % 400 == 0) {
            if (this -> day > 29) {
                this -> mon++;
                this -> day -= 28;
            } else {
                this -> mon++;
                this -> day -= 27;
            }
        }
        if(this -> mon > 12) {
            this->mon = 1;
            this->yr++;
        }
    }
