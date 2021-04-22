//
// Created by seraf on 16.03.2021.
//

#ifndef PROIECTOOP_REMINDER_H
#define PROIECTOOP_REMINDER_H

#include <memory>
#include "DateTime.h"

class Reminder {
protected:
    std::string message;
    DateTime remindTime;
    bool isImportant;
public:
    Reminder(std::string message, DateTime time, bool isImportant = false);
    Reminder(const Reminder& R);
    virtual ~Reminder();
    Reminder& operator=(const Reminder& R);
    friend std::ostream &operator<<(std::ostream &out, const Reminder &R);
    virtual void delay();
    virtual void print(std::ostream& os);
    void setMessage(std::string msg);
    void setDate(DateTime timeChange);
    void setImportant(bool important);
    virtual std::unique_ptr <Reminder> clone();
    std::string getMessage() const;
    DateTime getDate();
};


#endif //PROIECTOOP_REMINDER_H
