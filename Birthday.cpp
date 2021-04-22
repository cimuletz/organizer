//
// Created by seraf on 21.04.2021.
//

#include <memory>
#include "Birthday.h"
Birthday::Birthday(std::string name, int age, std::string message, DateTime time, bool important):name(name), age(age), Reminder(message, time, important) {}
void Birthday::setName(std::string name){
    this -> name = name;
}
void Birthday::setAge(int age){
    this -> age = age;
}
void Birthday::delay(){
    this -> remindTime.addYears(1);
}
std::unique_ptr <Reminder> Birthday::clone(){
    return std::make_unique <Birthday>(*this);
}