//
// Created by seraf on 16.03.2021.
//

#include "Reminder.h"
    Reminder::Reminder(std::string message, DateTime time, bool important): message(message), remindTime(time), isImportant(important){}
    Reminder::Reminder(const Reminder& R){
        this->message = R.message;
        this->remindTime = R.remindTime;
        this->isImportant = R.isImportant;
    }
    Reminder::~Reminder(){}
    Reminder& Reminder::operator=(const Reminder& R){
        if( &R != this ){
            this->message = R.message;
            this->remindTime = R.remindTime;
            this->isImportant = R.isImportant;
        }
        return *this;
    }
    std::ostream& operator<<(std::ostream& out, const Reminder &R){
        out << "Reminder!\n" << R.message << "\n";
        R.remindTime.printDate(std::cout);
        return out;
    }
    void Reminder::snooze(){
        this -> remindTime.addMinutes(10);
    }
    void Reminder::setMessage(std::string msg){
        this -> message = msg;
    }
    void Reminder::setDate(DateTime timeChange){
        this -> remindTime = timeChange;
    }
    void Reminder::setImportant(bool important){
        this -> isImportant = important;
    }
    std::string Reminder::getMessage() const{
        return this -> message;
    }
    DateTime Reminder::getDate() {
        return this -> remindTime;
    }
