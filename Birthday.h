//
// Created by seraf on 21.04.2021.
//

#ifndef SHOPPINGLIST_CPP_BIRTHDAY_H
#define SHOPPINGLIST_CPP_BIRTHDAY_H


#include "Reminder.h"

class Birthday: public Reminder {
    std::string name;
    int age;

public:
    explicit Birthday(std::string name, int age, std::string message, DateTime time, bool important = true);
    Birthday(const Birthday& b) = default;
    void setName(std::string name);
    void setAge(int age);
    ~Birthday() override = default;
    void delay() override;
    void print(std::ostream& os) override;
    std::unique_ptr <Reminder> clone() override;
};


#endif //SHOPPINGLIST_CPP_BIRTHDAY_H
