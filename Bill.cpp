//
// Created by seraf on 20.04.2021.
//

#include <memory>
#include "Bill.h"
Bill::Bill(double value, std::string company, std::string message, DateTime remindTime, bool important): Reminder(message, remindTime, important), company(company), value(value){}
//Bill::Bill(const Bill& b): Reminder(b), company(b.company), value(b.value){}
void Bill::setValue(double value){
    this -> value = value;
}
void Bill::setCompany(std::string company) {
    this -> company = company;
}
void Bill::delay(){
    this -> remindTime.addMonths(1);
}
std::unique_ptr <Reminder> Bill::clone(){
    return std::make_unique <Reminder> (*this);
}